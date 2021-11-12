#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using std::cout;
using std::ifstream;
using std::istringstream;
using std::string;
using std::vector;
using std::pair;

enum class State {kEmpty, kObstacle};
enum class SearchState {open,closed};

vector<State> ParseLine(string line) {
    istringstream sline(line);
    int n;
    char c;
    vector<State> row;
    while (sline >> n >> c && c == ',') {
      if (n == 0) {
        row.push_back(State::kEmpty);
      } else {
        row.push_back(State::kObstacle);
      }
    }
    return row;
}

vector<vector<State>> ReadBoardFile(string path) {
  ifstream myfile (path);
  vector<vector<State>> board{};
  if (myfile) {
    string line;
    while (getline(myfile, line)) {
      vector<State> row = ParseLine(line);
      board.push_back(row);
    }
  }
  return board;
}

string CellString(State cell) {
  switch(cell) {
    case State::kObstacle: return "⛰️   ";
    default: return "0   "; 
  }
}

vector<vector<bool>> initializeCLosedList(vector<vector<State>> board)
{
  int rows = board.size();
  int columns = board.at(0).size();
  vector<std::vector<bool> > closedList(
    rows,
    std::vector<bool>(columns));
  return closedList;
}

/**
 * UNFINISHED due misunderstanding in the video (we do not need to implement this version, because we will use A*)
 */

int getShortestPath(const vector<vector<State>> board,std::pair<int,int> start,std::pair<int,int> goal)
{
  vector<vector<bool>> closedList = initializeCLosedList(board);
  vector<pair<int,int>> openList;
  // start at start point
  pair<int,int> currentPosition = start;
  // repeat
  while(currentPosition != goal)
  {

    // check reachable neighbours of current position if they are still expanded (closed)
      SearchState left = SearchState::closed;
      if (currentPosition.first -1 >= 0)
      {
        if(board.at(currentPosition.first-1).at(currentPosition.second) == State::kEmpty)
        {
          left = SearchState::open;
        }
      }
      
        // if yes continue checking the open list
        // if no put them in the open-list
          // go through open-list
            // check gValue (how many expansions it took to get here)
            // expand the state with smallest gValue
  }
  // until goal is reached
  // return gValue (== shortest path) 
}

void PrintBoard(const vector<vector<State>> board) {
  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[i].size(); j++) {
      cout << CellString(board[i][j]);
    }
    cout << "\n";
  }
}

int main() {
  auto board = ReadBoardFile("../files/board_1");
  PrintBoard(board);
}