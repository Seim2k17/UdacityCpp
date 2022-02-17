#include <iostream>

class MemClass
{
    public:
        MemClass()
        {
            //_myint = new int;
            _myInt = (int *) malloc(sizeof(int));
        }

        ~MemClass()
        {
            free(_myInt);
        }

        void printOwnAdress()
        {
            std::cout << "Adress on stack: " << this << std::endl;
        }

        void printMemberAdress()
        {
            std::cout << "Managing mem-block on the heap: " << _myInt << std::endl;
        }

    private:

        int* _myInt;
};


int main()
{
    MemClass memClassA;
    memClassA.printOwnAdress();
    memClassA.printMemberAdress();

    MemClass memClassB(memClassA);
    memClassB.printOwnAdress();
    memClassB.printMemberAdress();

    // here the programm crashes because in the destructor of MemClass _myInt is deallocated once in the Instance of memClassA and then again from memClassB
    // --> double free (it has the same memory-adress due default copy-behaviour)

    return 0;
}