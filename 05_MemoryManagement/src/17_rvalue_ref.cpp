#include <iostream>

void myFunction(int &val)
{
    std::cout << "val = " << val << std::endl;
}
#include <iostream>

int main()
{
    int h = 42;
    myFunction(h);

    // error: cannot bind non-const lvalue reference of type ‘int&’ to an rvalue of type ‘int’
    // myFunction(42);

    int k = 23; 
    // error: cannot bind non-const lvalue reference of type ‘int&’ to an rvalue of type ‘int’
    // myFunction(j+k);

    int i = 1; 
    int j = 2; 
    int l = i + j; 
    int &&m = i + j; 

    std::cout << "l = " << l << ", m = " << m << std::endl;

    return 0; 
}

