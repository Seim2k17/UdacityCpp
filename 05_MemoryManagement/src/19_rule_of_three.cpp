#include <stdlib.h>
#include <iostream>

class MovableClass
{
    public:
        MovableClass(size_t val) {
            _size = val;
            _data = new int[_size];

            std::cout << "CREATING instance of  MovableClass at " << this << " allocated with size= " << _size * sizeof(int) << " bytes " << std::endl;
        };

        ~MovableClass()
        {
            std::cout << " DELETING instance of MovableClass at " << this << std::endl;
            // free stuff
            delete[] _data;
        }

        // copy cdor, takes reference to the source, const input (can't change the source)
        MovableClass(const MovableClass &source) {
            // copy by value the size
            _size = source._size;
            // allocate it own memory
            _data = new int[_size];
            // deep copy of data
            *_data = *source._data;
            std::cout << " COPYING content of instance " << &source << " to instance " << this << std::endl;
        };

        // copy assignment operator, const input (can't change the source)
        MovableClass &operator=(const MovableClass &source)
        {
            std::cout << "ASSIGNING content of instance " << &source << " to instance " << this << std::endl;
            // accepted boilerplate-code to protect about self-assignment (obj1 = obj1)
            if (this == &source) {return *this;}

            // when copying we assume that the object has lived before -> deallocate the existing data
            delete[] _data;
            // allocate new memory
            _data = new int[_size];
            // copying the content & member
            *_data =*source._data;
            _size = source._size;
            return *this;
        }

    private:
        int _size;
        int* _data;
};

MovableClass createObject(int size)
{
    MovableClass obj(size);
    return obj; // return by value -> make a temporary copy as an rvalue
}

int main()
{
    MovableClass obj1(10);      // regular cdor
    MovableClass obj2(obj1);    // copy cdor
    obj2 = obj1;                // copy assignment operator

    
    MovableClass obj3 = obj1;               // copy cdor alternate syntax, instantiate obj3 in the same satement->copy assignment is not called
    MovableClass obj4 = createObject(15);   // createObject() returns a temp object as an rvalue which is passed to the copy constructor
                                            // no copying printout because the copy constructor is called on the temporary object
                                            // 2 expensive mem operations here:     1. creation of an temporary rvalue
                                            //                                      2. execution of the copy constructor
    MovableClass obj5(createObject(12));    // also possible like last statement

    obj4 = createObject(10);                // also expensive:  1. erase obj4 memory
                                            //                  2. reallocate during creation of temp object
                                            //                  3. copy the data from the temp object to obj4
}                                                           