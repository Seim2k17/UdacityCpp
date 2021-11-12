#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using std::cout;
using std::ifstream;
using std::string;
using std::vector;

std::vector<int> ParseLine(std::string inputString)
{
    std::vector<int> numbers{};

    std::istringstream streamLine(inputString);
    int number;
    char delimiter;
    while(streamLine >> number >> delimiter)
    {
        numbers.push_back(number);
    }
    
    return numbers;
}

void outputVector(std::vector<int> vec)
{
    for(auto i: vec )
    {
        std::cout << i ;
    }
    std::cout << std::endl;
}

void ReadBoardFile(string path) {
  ifstream myfile (path);
  if (myfile) {
    string line;
    while (getline(myfile, line)) {
      cout << line << "\n";
      auto vec1 = ParseLine(line);
      outputVector(vec1);
    }
  }
}

void PrintBoard(const vector<vector<int>> board) {
  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[i].size(); j++) {
      cout << board[i][j];
    }
    cout << "\n";
  }
}

//#include "test.cpp" // For testing.

int main() {
  //ReadBoardFile("1.board");
  ReadBoardFile("../files/board_1");

  //TestParseLine(); // For testing.
  // Leave commented out.

  // PrintBoard(board);
}