#include <iostream>
#include <memory>

// usage of a unique pointer

class DataClass
{
    public:
        DataClass(){};
        DataClass(std::string msg){};

        void setText(std::string msg)
        {
            textData = msg;
        }

        ~DataClass() 
        {
            std::cout << "dedor called with data " << textData << std::endl;
        }


    private:
        std::string textData;

};

int main()
{
    // create unique pointer to proprietary class
    std::unique_ptr<DataClass> smart0 = std::make_unique<DataClass>("blub");
    std::unique_ptr<DataClass> smartPnt1(new DataClass());
    std::unique_ptr<DataClass> smartPnt2(new DataClass("test"));

    // call member function using ->
    smartPnt1->setText("bla");

    // use the dereference operator *
    *smartPnt2 = *smartPnt1;

    int* testStack = new int(9);
    int* testStack2 = new int(7);

    // use .get() function to retrieve a raw pointer to the object
    std::cout << "Objects have stack adresses " <<  smartPnt1.get() << " and " <<  smartPnt2.get() << std::endl;
    std::cout << "Objects have heap adresses " <<  &testStack << " and " <<  &testStack2 << std::endl;

    delete testStack;
    delete testStack2;
    
    return 0;
}