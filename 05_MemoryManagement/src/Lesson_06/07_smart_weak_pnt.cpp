#include <iostream>
#include <memory>

int main()
{
    std::shared_ptr<int> mySharedPtr(new int);
    {
    
        std::cout << "shared pointer count = " << mySharedPtr.use_count() << std::endl;

        std::weak_ptr<int> myWeakPtr1(mySharedPtr);
        std::weak_ptr<int> myWeakPtr2(myWeakPtr1);
        // expect 1 -> weak pnts have no effect on the refcount
        std::cout << "shared pointer count = " << mySharedPtr.use_count() << std::endl;
        std::shared_ptr<int> mySharedPtr2(mySharedPtr);
        // expect 2
        std::cout << "shared pointer count = " << mySharedPtr.use_count() << std::endl;

        // std::weak_ptr<int> myWeakPtr3(new int); // COMPILE ERROR

        std::weak_ptr<int> myWeakPtr3;
        // expect 0 -> no increase
        std::cout << "shared pointer count = " << myWeakPtr3.use_count() << std::endl;
    }
    // expect 1
    std::cout << "shared pointer count = " << mySharedPtr.use_count() << std::endl;
    return 0;
}