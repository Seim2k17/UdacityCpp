// to alloc mem these headers needs to be included
#include <stdlib.h>
#include <malloc.h>

#include <stdio.h>
// syntax: 
// pointer_name = (cast-type)* malloc(size)
// pointer_name = (cast-type)* calloc(num_elements, size_element)



int main() 
{ 
    int *p = (int*)malloc(sizeof(int)); // we 
    printf("address=%p, value=%d\n", p, *p);
    int *q = (int*)malloc(sizeof(int)); 
    printf("address=%p, value=%d\n", q, *q);

    struct MyStruct {
        int i; //4 byte
        double d; // 8 byte
        char a[5]; // 5 byte
    };

    MyStruct *pnt = (MyStruct*)calloc(4,sizeof(MyStruct));
    pnt[0].i = 1; pnt[0].d = 3.14159; pnt[0].a[0] = 'a';
    printf("address=%p, valueI=%d size=%ld bytes\n", pnt, pnt->i, sizeof(MyStruct));
    
    double ds = 3.4;
    int j = 1;
    char b[5];

    printf("sizeof(int): %ld, sizeof(double): %ld, sizeof(char): %ld\n.",sizeof(j),sizeof(ds),sizeof(b));


    int *iPnt = (int*)malloc(3*sizeof(int));
    iPnt[0]=100;iPnt[1]=24556;iPnt[2]=322333;

    printf("address=%p, size=%ld bytes\n", iPnt, sizeof(iPnt));
    printf("[0]: %d\n", *(iPnt));
    printf("[1]: %d\n", *(iPnt+1));
    printf("[2]: %d\n", *(iPnt+2));
    printf("[3]: %d\n", *(iPnt+3)); //INVALID, because it can be reused by any other programm

    iPnt = (int*)realloc(iPnt,4*sizeof(int));
    iPnt[3]=224211904;
    printf("[3]: %d\n", *(iPnt+3)); //now VALID, because now its reserved fpr iPnt

    free(iPnt);
    free(pnt);
    free(p);
    free(q);

    return 0; 
}