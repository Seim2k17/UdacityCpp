#include <iostream>
#include <thread>

class Vehicle
{
public:
    Vehicle() : _id(0) {}
    void addID(int id) { _id = id; }
    void printID()
    {
        std::cout << "Vehicle ID=" << _id << std::endl;
    }

private:
    int _id;
};

int main()
{
    // create thread
    Vehicle v1, v2;
    // when calling member function from a object passed by value (v1) -> a new copy is created and does not affect the original living in the main thread
    std::thread t1 = std::thread(&Vehicle::addID, v1, 1); // call member function on object v
    // when calling a member function from a object passed by ref, changes to its _id variable will also be visible in main
    std::thread t2 = std::thread(&Vehicle::addID, &v2, 2); // call member function on object v

    // wait for thread to finish
    t1.join();
    t2.join();

    // print Vehicle id
    v1.printID();
    v2.printID();

    return 0;
}