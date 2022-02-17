#include <string.h>
#include <stdio.h>

int main()
{
    
    char str[5]; // instead we need 14bytes
    strcpy(str,"BufferOverrun");
    printf("%s",str);

    // unintialized variable (a)
    int a;
    int b=a*42;
    printf("%d",b);

    // access memory which is already deallocated
    char *pStr=new char[25];
    delete[] pStr;
    strcpy(pStr, "Invalid Access");

    return 0;
}
