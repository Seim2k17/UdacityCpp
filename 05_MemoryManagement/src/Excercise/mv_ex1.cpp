/* 
Memory Management exercises part 1: Pass data between functions without using move semantics
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>

using namespace std;

// pass back by pointer (old C++)
const int array_size = 1e6; // determines size of the random number array
vector<int> *RandomNumbers1()
{
    vector<int> *random_numbers = new vector<int>[array_size]; // allocate memory on the heap...
    for (int i = 0; i < array_size; i++)
    {
        int b = rand();
        (*random_numbers).push_back(b); // ...and fill it with random numbers
    }

    return random_numbers; // return pointer to heap memory
}

// pass back by reference (old C++)
void RandomNumbers2(vector<int> &random_numbers)
{
    random_numbers.resize(array_size); // expand vector to desired size
    for (int i = 0; i < array_size; i++)
    {
        random_numbers[i] = rand();
    }
}

int main()
{
    /* EXERCISE 1-1: Get access to random data using a returned pointer from function RandomNumbers1 and make sure that there are no memory leaks.*/
    // store the data in a suitable variable named 'random_numbers_1' and free the associated memory immediately afterwards

    // TODO: SOLUTION to exercise 1-1
    // return-by-pointer
    auto random_numbers_1 = RandomNumbers1();
    //for (auto it = random_numbers_1->begin();it!=random_numbers_1->end();it++)
    //{
        //printf("it: %i",*it);
    //}
    printf("it: %p",&random_numbers_1);
    delete [] random_numbers_1;
    printf("it: %p",&random_numbers_1);

    /* EXERCISE 1-2: Get access to data using pass-by-reference */
    // store the data in a suitable variable named 'random_numbers_2'

    vector<int> random_numbers_2 = {};
    printf("Size before: %ld",random_numbers_2.size());
    RandomNumbers2(random_numbers_2);
    printf("Size after: %ld",random_numbers_2.size());

    // TODO: SOLUTION to exercise 1-2
    // create identifier to pass to the function
    
}