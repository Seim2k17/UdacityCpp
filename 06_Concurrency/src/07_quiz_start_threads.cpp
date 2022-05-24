#include <iostream>
#include <thread>

void threadFunctionEven()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(1)); // simulate work
    std::cout << "Even thread\n";
}

void threadFunctionOdd()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(1)); // simulate work
    std::cout << "Odd thread\n";
}
/* Student Task START */

/* Student Task END */

int main()
{
    /* Student Task START */
    for(uint16_t i=1;i<=6;i++)
    {
        if(i%2 == 0)
        {
            std::thread t(threadFunctionEven);
            //t.join();
            t.detach();
        }
        else
        {
            std::thread s(threadFunctionOdd);
            //s.join();
            s.detach();
        }
    }

    /* Student Task END */

    // ensure that main does not return before the threads are finished
    std::this_thread::sleep_for(std::chrono::milliseconds(1)); // simulate work



    std::cout << "End of main is reached" << std::endl;
    return 0;
}
