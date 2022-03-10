#include <iostream>

using namespace std;

// This class for managing a template-based heap ressource implements move semantics
template <class T>
class MyClass
{
    T *data = nullptr;

public:
    MyClass() {printf("use standard cdor\n");}

    // move constructor
    MyClass(MyClass &&other)
    {
        printf("use move cdor\n");
        data = other.data;
        other.data = nullptr;
    }

    // move assignment operator
    MyClass &operator=(MyClass &&other)
    {
        printf("use move assignment op\n");
        if (this != &other)
        {
            if (data)
            {
                delete data;
            }
            data = other.data;
            other.data = nullptr;
        }

        return *this;
    }

    ~MyClass()
    {
        std::cout << "use dedor of: " << this << std::endl;
        if (data)
        {
            delete data;
        }
    }


private:
    // copy constructor
    MyClass(const MyClass &){printf("use copy cdor\n");};

    // copy assignment operator
    MyClass &operator=(const MyClass &){printf("use copy assignment op\n");};
};

int main()
{
    /* EXERCISE 3-1: create an instance h1 of class MyClass with data of type 'double' using the regular constructor */
    // TODO: SOLUTION 3-1
    MyClass<double> h1;
    
    // /* EXERCISE 3-2: create an instance h2 of class MyClass using the move constructor (moving from h1) */
    // TODO: SOLUTION 3-2
    MyClass<double> h2(std::move(h1));

    /* EXERCISE 3-3: disable copying for class MyClass */
    // set copy cdor and copy assignment op private
    // TODO: SOLUTION 3-3
    // h2 = h1;
}