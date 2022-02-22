#include <iostream>
#include <string>

void myFunction(int &val)
{
    std::cout << "val = " << val << std::endl;
}

void rvalRefTest()
{
    // https://medium.com/@dhaneshvb/how-to-crack-the-confusing-world-of-lvalues-and-rvalues-in-c-it-is-easy-61c32ced51ce
    std::string s1= "Good ";
    std::string s2= "morning ";
    std::string&& text = s1+s2;
    std::cout << text << std::endl;
    // and now i can change this temporary s1+s2
    text += ", people.";
    std::cout << text << std::endl;
}

int main()
{
    int h = 42;
    myFunction(h);

    // error: cannot bind non-const lvalue reference of type ‘int&’ to an rvalue of type ‘int’
    // myFunction(42);

    int k = 23; 
    // error: cannot bind non-const lvalue reference of type ‘int&’ to an rvalue of type ‘int’
    // myFunction(j+k);

    // i, j are lvalues, 1,2 are rvalues
    int i = 1; 
    int j = 2;
    // l as another lvalue, (i+j) created as a rvalues which holds the result of the addition before being copied into the memory location of l
    // quite a lot copy work
    int l = i + j; 
    // more efficiently with rlvalue refs; &&m creates a rvalue ref to which the adress of the temporary object is assigned, that holds the result of the addition
    // instead of creating rvalue i+j then copying it and then deleting, we can hold the temporary object in memory -> this is more efficient than before
    int &&m = i + j; 

    // here a few bytes of storage is not a big win but this is the start for move semantics

    std::cout << "l = " << l << ", m = " << m << std::endl;

    rvalRefTest();

    return 0; 
}

