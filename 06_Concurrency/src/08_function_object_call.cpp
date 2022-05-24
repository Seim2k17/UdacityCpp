#include <iostream>
#include <thread>

class Vehicle
{
public:


    void operator()()
    {
        std::cout << "Vehicle object has been created \n" << std::endl;
    }

};


int main()
{

    Vehicle v;

    // create thread 
    //std::thread t(Vehicle()); // C++'s most vexing parse
    std::thread t(v);

    // do something in main()
    std::cout << "Finished work in main \n";

    // wait for thread to finish
    t.join();

    return 0;
}