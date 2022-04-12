#include <iostream>
#include <memory>

class PointerClass
{
    // as we do not have implemented the move constructor or move_assignment operator the compiler uses the default implementation here
    public:
        PointerClass(int val) : _member(val) {}
        void printVal() {std::cout << ", managed object " << this << " with val " << _member << std::endl;}
    private:
        int _member;
};

// here we make a local copy of the unique pointer, which in fact is a break to the definition of unique pointer
// but with the correct call (move-semantics) we only copy the handle to the pointer
void f(std::unique_ptr<PointerClass> ptr)
{
    std::cout << "unique_ptr(called by f) " << &ptr;
    ptr->printVal();
}


int main()
{
    // the unique pointer is a stack variable, with the factory-function make_unique an instance is createdand assigned to a unique pointer instance
    // the object it manages (23) is heap-allocated
    std::unique_ptr<PointerClass> uniquePtr = std::make_unique<PointerClass>(23);
    std::cout << "unique-ptr " << &uniquePtr;
    uniquePtr->printVal();

    // rule of 5 implementation-> use move semantics -> transfering move-semantics from main into the scope of f()
    // -> 
    f(std::move(uniquePtr));

    // f(uniquePtr); will not compile -> needs to be moved

    // uniquePtr is still there, but pointing to NULL, empty shell
    if(uniquePtr)
    {
        std::cout << "uniquePtr still active" << std::endl;
        uniquePtr->printVal();
    }

    /*
    e.g. with this output we see that move semantics worked (stack-adress is different but the adress of the managed object remains)
        unique-ptr0x7fffd94fe5b8, managed object 0x5589cb9e5eb0 with val 23
        unique_ptr0x7fffd94fe5c0, managed object 0x5589cb9e5eb0 with val 23
    */

    return 0;
}