#include <stdio.h>

void CallByValue(int i)
{
    int j= 1;
    printf("Call-by-Value: %p\n",&j);
    printf("size of int(j): %lu\n",sizeof(j));
}

void CallByReference(int &i)
{
    int j= 1;
    printf("Call-by-Ref: %p\n",&j);
    printf("size of int(j): %lu\n",sizeof(j));
}

void CallByPointer(int *i)
{
    int j= 1;
    printf("Call-by-Pointer: %p\n",&j);
    printf("size of int(*j): %lu\n",sizeof(i));
}


int main()
{
    int i=0;
    printf("stack bottom: %p\n",&i);

    CallByValue(i);

    CallByReference(i);

    CallByPointer(&i);
    
    return 0;
}