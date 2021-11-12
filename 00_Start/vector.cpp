#include <iostream>
#include <vector>
using std::cout;
using std::vector;

void PrintBoard(vector<vector<int>>& board)
{
    // Write your double loop here.
    for(vector<int> i: board)
    {
        for( int k=0; k< i.size(); k++)
        {
            cout << i[k] ;
            
        }
        cout << "\n";
    
    }
}

int main() {
    // Add your code here.
    vector<vector<int>> b {{1, 2},
                           {3, 4},
                           {5, 6}};

    PrintBoard(b);
    return 0;
}