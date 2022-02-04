#include <stdio.h>
#include <iostream>

void myFunc()
{
    int k=3;
    printf("3: %p \n",&k);
}

void overFlow(int i)
{
    int n = i;
    printf(" %i : %p \n",n,&n);
    overFlow(++i);
    
}

bool MyLocalFunction(int myInt)
{
	bool isBelowThreshold = myInt < 42 ? true : false;
	return isBelowThreshold;
}

void AddFour(int &val)
{
    val += 4;
}

void AddSix(int *val)
{
    *val += 6; 
}

int main()
{
    //1. calls we se st like:
    /*  1: 0x7ffc99a9ea7c 
        2: 0x7ffc99a9ea80 
        3: 0x7ffc99a9ea54 
        4: 0x7ffc99a9ea84 
    from 1-2 and 2-4 increase of 4bytes
    */
    int i= 1;
    printf("1: %p \n",&i);

    int j= 2;
    printf("2: %p \n",&j);

    myFunc();

    int l= 4;
    printf("4: %p \n",&l);


    // generate stack overflow to get size of the stack:

    //overFlow(0);
    
    bool res = MyLocalFunction(23);

    std::cout << (res ? "true" : "false") << std::endl;

    int val = 0;
    AddFour(val);
    val += 2;

    std::cout << "val = " << val << std::endl;

 
    int val2 = 0;
    AddFour(val2);
    AddSix(&val2);

    std::cout << "val = " << val2 << std::endl;
 
    
    return 0;
}