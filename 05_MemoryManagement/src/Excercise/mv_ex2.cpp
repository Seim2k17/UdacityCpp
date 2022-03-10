/* 
Memory Management exercises part 2: Use move semantics implicitly as part of the STL
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int array_size = 1e6;
vector<int> RandomNumbers3()
{
    vector<int> random_numbers;
    random_numbers.resize(array_size);
    for (int i = 0; i < array_size; i++)
    {
        random_numbers[i] = rand();
    }
    return random_numbers; // return-by-value of the STL vector
}

int main()
{
    /* EXERCISE 2-1: Return large objects using move semantics in the STL */
    // store the data in a suitable variable named 'random_numbers_3'

    // SOLUTION to exercise 2-1
    vector<int> random_numbers_3 = std::move(RandomNumbers3()); // stl retuzrns datastructure vector not by value but with moive_semantics under the hood

    
}