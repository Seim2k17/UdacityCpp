#include <stdlib.h>
#include <iostream>

class MyMovableClass
{
private:
    int _size;
    int *_data;

public:
    MyMovableClass(size_t size) // constructor
    {
        _size = size;
        _data = new int[_size];
        std::cout << "CREATING instance of MyMovableClass at " << this << " allocated with size = " << _size*sizeof(int)  << " bytes" << std::endl;
    }

    ~MyMovableClass() // 1 : destructor
    {
        std::cout << "DELETING instance of MyMovableClass at " << this << std::endl;
        delete[] _data;
    }
    
    MyMovableClass(const MyMovableClass &source) // 2 : copy constructor
    {
        _size = source._size;
        _data = new int[_size];
        *_data = *source._data;
        std::cout << "COPYING content of instance " << &source << " to instance " << this << std::endl;
    }
    
    MyMovableClass &operator=(const MyMovableClass &source) // 3 : copy assignment operator
    {
        std::cout << "ASSIGNING content of instance " << &source << " to instance " << this << std::endl;
        if (this == &source)
            return *this;
        delete[] _data;
        _data = new int[source._size];
        *_data = *source._data;
        _size = source._size;
        return *this;
    }


    MyMovableClass(MyMovableClass &&source) // 4 : move constructor
    {
        std::cout << "MOVING (c’tor) instance " << &source << " to instance " << this << std::endl;
        // copies the data handle from source to target and imm. invalidates the source
        // ownership has been moved
        _data = source._data;
        _size = source._size;
        source._data = nullptr;
        source._size = 0;
    }

    MyMovableClass &operator=(MyMovableClass &&source) // 5 : move assignment operator
    {
        std::cout << "MOVING (assign) instance " << &source << " to instance " << this << std::endl;
        if (this == &source)
            return *this;

        delete[] _data;

        _data = source._data;
        _size = source._size;

        source._data = nullptr;
        source._size = 0;

        return *this;
    }     

};

void useObject(MyMovableClass obj)
{
    std::cout << "using object " << &obj << std::endl;
}

int main()
{

    bool moveSemantics = true;

    if (!moveSemantics)
    {
        MyMovableClass obj1(100), obj2(200); // constructor

        MyMovableClass obj3(obj1); // copy constructor

        MyMovableClass obj4 = obj1; // copy constructor

        obj4 = obj2; // copy assignment operator
    }
    else
    {
        std::cout << "1: create instance by calling c'tor " << std::endl;
        MyMovableClass obj1(100); // constructor
        
        std::cout << "2: use by value -> make a copy with a temporary obj-copy of obj1, delted afterwards " << std::endl;
        useObject(obj1);

        std::cout << "3: " << std::endl;
        obj1 = MyMovableClass(200); // move assignment operator
        
        std::cout << "4: call with an temp. instance of the class as an argument as an rvalue" << std::endl;
        MyMovableClass obj2 = MyMovableClass(300); // move constructor 

        std::cout << "5: transfering ownership of the temp. object, no deep copy" << std::endl;
        useObject(std::move(obj2));

        std::cout << "6: transfering ownership of a temp. with a lvalue ref" << std::endl;
        
        MyMovableClass obj3(500);
        std::cout << "  transfering ownership from obj3 to obj from useObject." << std::endl;
        useObject(std::move(obj3));
        //useObject(std::move(1500));
    }


    return 0;
}
