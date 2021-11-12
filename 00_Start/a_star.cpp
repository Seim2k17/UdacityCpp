#include <algorithm>  // for sort
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using std::cout;
using std::sort;
using std::ifstream;
using std::istringstream;
using std::string;
using std::vector;
using std::abs;

enum class State {kEmpty, kObstacle, kClosed, kPath};
// directional deltas
const int delta[4][2]{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};


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


// Calculate the manhattan distance
int Heuristic(int x1, int y1, int x2, int y2) {
  return abs(x2 - x1) + abs(y2 - y1);
}


/** 
 * Add a node to the open list and mark it as open. 
 */
void AddToOpen(int x, int y, int g, int h, vector<vector<int>> &openlist, vector<vector<State>> &grid) {
  // Add node to open vector, and mark grid cell as closed.
  openlist.push_back(vector<int>{x, y, g, h});
  grid[x][y] = State::kClosed;
}

bool Compare(const vector<int> vec1, const vector<int> vec2)
{
 int f1=vec1.at(2)+vec1.at(3);
 int f2=vec2.at(2)+vec2.at(3);
 return(f1>f2);
}  

/**
 * Sort the two-dimensional vector of ints in descending order.
 */
void CellSort(vector<vector<int>> *v) {
  sort(v->begin(), v->end(), Compare);
}



/** 
 * Implementation of A* search algorithm
 */
vector<vector<State>> Search(vector<vector<State>> grid, int init[2], int goal[2]) {
  // Create the vector of open nodes.
  vector<vector<int>> open {};
 
    int g = 0;
    int h = Heuristic(init[0], init[1],goal[0],goal[1] );
    AddToOpen(init[0],init[1],g,h,open,grid);

    // TODO: while open vector is non empty {
    while(!open.empty())
    {
    
        CellSort(&open);
        auto current = open.back();
        int x = current[0];
        int y = current[1];
        open.pop_back();
        grid[x][y] = State::kPath;

        // Check if we're done.
        if (x == goal[0] && y == goal[1]) {
        return grid;
        }
    // If we're not done, expand search to current node's neighbors. This step will be completed in a later quiz.
    // ExpandNeighbors

    }
    
  // We've run out of new nodes to explore and haven't found a path.



  cout << "No path found!" << "\n";
  return std::vector<vector<State>>{};
}

bool CheckValidCell(int x, int y, vector<vector<State>>& grid)
{
    if( x <= grid.size() && y <= grid.at(x).size())
    {
        if(grid.at(x).at(y) == State::kEmpty)
        {
            return true;
        }
    }
    return false;
}

void ExpandNeighbors(const vector<int>& current, vector<vector<int>> openlist,vector<vector<State>> grid, int goal[2])
{
  // Get current node's data.
  int x = current[0];
  int y = current[1];
  int g = current[2];

  // Loop through current node's potential neighbors.
  for (int i = 0; i < 4; i++) {
    int x2 = x + delta[i][0];
    int y2 = y + delta[i][1];

    // Check that the potential neighbor's x2 and y2 values are on the grid and not closed.
    if (CheckValidCell(x2, y2, grid)) {
      // Increment g value and add neighbor to open list.
      int g2 = g + 1;
      int h2 = Heuristic(x2, y2, goal[0], goal[1]);
      AddToOpen(x2, y2, g2, h2, openlist, grid);
        }
    }

}

string CellString(State cell) {
  switch(cell) {
    case State::kObstacle: return "⛰️   ";
    case State::kPath: return "🚗   ";
    default: return "0   "; 
  }
}


void PrintBoard(const vector<vector<State>> board) {
  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[i].size(); j++) {
      cout << CellString(board[i][j]);
    }
    cout << "\n";
  }
} 


/* 

TESTING-SECTION

*/



void PrintVectorOfVectors(vector<vector<int>> v) {
  for (auto row : v) {
    cout << "{ ";
    for (auto col : row) {
      cout << col << " ";
    }
    cout << "}" << "\n";
  }
}

void PrintVectorOfVectors(vector<vector<State>> v) {
  for (auto row : v) {
    cout << "{ ";
    for (auto col : row) {
      cout << CellString(col) << " ";
    }
    cout << "}" << "\n";
  }
}

void TestHeuristic() {
  cout << "----------------------------------------------------------" << "\n";
  cout << "Heuristic Function Test: ";
  if (Heuristic(1, 2, 3, 4) != 4) {
    cout << "failed" << "\n";
    cout << "\n" << "Heuristic(1, 2, 3, 4) = " << Heuristic(1, 2, 3, 4) << "\n";
    cout << "Correct result: 4" << "\n";
    cout << "\n";
  } else if (Heuristic(2, -1, 4, -7) != 8) {
    cout << "TestHeuristic Failed" << "\n";
    cout << "\n" << "Heuristic(2, -1, 4, -7) = " << Heuristic(2, -1, 4, -7) << "\n";
    cout << "Correct result: 8" << "\n";
    cout << "\n";
  } else {
    cout << "passed" << "\n";
  }
  return;
}

void TestAddToOpen() {
  cout << "----------------------------------------------------------" << "\n";
  cout << "AddToOpen Function Test: ";
  int x = 3;
  int y = 0;
  int g = 5;
  int h = 7;
  vector<vector<int>> open{{0, 0, 2, 9}, {1, 0, 2, 2}, {2, 0, 2, 4}};
  vector<vector<int>> solution_open = open; 
  solution_open.push_back(vector<int>{3, 0, 5, 7});
vector<vector<State>> grid{{State::kClosed, State::kObstacle, State::kEmpty, State::kEmpty, State::kEmpty, State::kEmpty},
                            {State::kClosed, State::kObstacle, State::kEmpty, State::kEmpty, State::kEmpty, State::kEmpty},
                            {State::kClosed, State::kObstacle, State::kEmpty, State::kEmpty, State::kEmpty, State::kEmpty},
                            {State::kClosed, State::kObstacle, State::kEmpty, State::kEmpty, State::kEmpty, State::kEmpty},
                            {State::kClosed, State::kClosed, State::kEmpty, State::kEmpty, State::kObstacle, State::kEmpty}};
  vector<vector<State>> solution_grid = grid;
  solution_grid[3][0] = State::kClosed;
  AddToOpen(x, y, g, h, open, grid);
  if (open != solution_open) {
    cout << "failed" << "\n";
    cout << "\n";
    cout << "Your open list is: " << "\n";
    PrintVectorOfVectors(open);
    cout << "Solution open list is: " << "\n";
    PrintVectorOfVectors(solution_open);
    cout << "\n";
  } else if (grid != solution_grid) {
    cout << "failed" << "\n";
    cout << "\n";
    cout << "Your grid is: " << "\n";
    PrintVectorOfVectors(grid);
    cout << "\n";
    cout << "Solution grid is: " << "\n";
    PrintVectorOfVectors(solution_grid);
    cout << "\n";
  } else {
    cout << "passed" << "\n";
  }
  cout << "----------------------------------------------------------" << "\n";
  return;
}

int main() {
  int init[2]{0,0};
  int goal[2]{4,5};
  auto board = ReadBoardFile("../files/board_1");
  auto solution = Search(board, init, goal);
  PrintBoard(solution);
  // Tests
  //TestHeuristic();
  //TestAddToOpen();
}


void getShortestPath()
{

    /*
    Search( grid, initial_point, goal_point ) :

        Initialize an empty list of open nodes.

        Initialize a starting node with the following:
            x and y values given by initial_point.
            g = 0, where g is the cost for each move.
            h given by the heuristic function (a function of the current coordinates and the goal).

        Add the new node to the list of open nodes.

        while the list of open nodes is nonempty:
            Sort the open list by f-value
            Pop the optimal cell (called the current cell).
            Mark the cell's coordinates in the grid as part of the path.

            if the current cell is the goal cell:
                return the grid.

            else, expand the search to the current node's neighbors. This includes the following steps:
                Check each neighbor cell in the grid to ensure that the cell is empty: it hasn't been closed and is not an obstacle.
                If the cell is empty, compute the cost (g value) and the heuristic, and add to the list of open nodes.
                Mark the cell as closed.

        If you exit the while loop because the list of open nodes is empty, you have run out of new nodes to explore and haven't found a path.
    */
   /*
   The code for the A* search algorithm has been broken down into the following functions:

    CellSort() - sorts the open list according to the sum of h + g
    ExpandNeighbors() - loops through the current node's neighbors and calls appropriate functions to add neighbors to the open list
    CheckValidCell() - ensures that the potential neighbor coordinates are on the grid and that the cell is open
    Heuristic() - computes the distance to the goal
    AddToOpen() - adds the node to the open list and marks the grid cell as closed
    */
}

