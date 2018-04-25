#include <iostream>
#include <cassert>
#include <vector>
#include <deque>

using namespace std;

// Infinite grid of B & W, ant is facing R
//      Ant actions:
//              - W -> B, turns 90deg clockwise moves forward
//              - B -> W, turns 90deg counter-clockwise moves forward
// Write a program that simulates the first K moves that the ant makes
// and print the final board.
//
// How does the board initially look?

void printMoves(int K) {
  deque<deque<bool> > grid;
  deque<bool> k;
  for (int i = 0; i < 24; i++) {
    grid.push_back(k);
    grid[i].insert(grid[i].begin(), 24, 0);
  }
  int dir = 0;
  int row = 12, col = 12;

  for (int i = 0; i < K; i++) {
    if ((row > grid.size() - 1) || (col > grid[i].size() - 1)) {
      // increase rows + cols
      for (int h = 0; h < 20; h++) {
        grid[i].insert(grid[i].begin()+row-1,20, 0);
      }
    }
    if ((row < 0) || (col < 0)) {
      // reposition
      deque<bool> k;
      k.insert(k.begin(), row, 0);
      for (int h = 0; h < col; h++) {
        grid.push_front(k);
      }
      row += row;
      col += col;
    }

    if (grid[row][col]) {
      if (dir < 3) dir+= 1;
      else dir = 0;
      grid[row][col] = 0;
    } else {
      if (dir > 0) dir -= 1;
      else dir = 4;
      grid[row][col] = 1;
    }

    if (dir == 0) row += 1;
    else if (dir == 1) col += 1;
    else if (dir == 2) row -= 1;
    else col -= 1;
  }
  for (int i = 0; i < grid.size(); i++) {
    for (int j = 0; j < grid[i].size(); j++) {
      cout << grid[i][j] << " ";
    }
    cout << endl;
  }
}

int main() {
  int k;
  cin >> k;
  printMoves(k);
  return 0;
}
