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


void f(std::shared_ptr<PointerClass> ptr)
{
    std::cout << "shared_ptr(called by f) (ref_cnt= " << ptr.use_count() << ") " << &ptr;
    ptr->printVal();
}


int main()
{
    std::shared_ptr<PointerClass> sharedPtr = std::make_shared<PointerClass>(23);
    std::cout << "shared-ptr  (ref_cnt= " << sharedPtr.use_count() << ") "<< &sharedPtr;
    sharedPtr->printVal();

    // no move needed, can be passed by value safely / only the reference count increases, while the managed object stays the same
    // coul use weak ptr as well, only difference that the reference count would not increase
    //f(std::move(sharedPtr));
    f(sharedPtr);

    // sharedPtr is still there, with decrease of reference count
    if(sharedPtr)
    {
        std::cout << "sharedPtr still active" << std::endl;
        sharedPtr->printVal();
    }

    std::cout << "shared-ptr  (ref_cnt= " << sharedPtr.use_count() << ") "<< &sharedPtr;
    sharedPtr->printVal();
    /*
    e.g. with this output we see that move semantics worked (stack-adress is different but the adress of the managed object remains)
        unique-ptr0x7fffd94fe5b8, managed object 0x5589cb9e5eb0 with val 23
        unique_ptr0x7fffd94fe5c0, managed object 0x5589cb9e5eb0 with val 23
    */

    return 0;
}