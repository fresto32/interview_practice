#include <iostream>
using namespace std;
template <size_t row, size_t col>
void DFS(int (&arr)[row][col], int coli, int rowi, bool (&visited)[row][col], 
    int &size) {
  visited[rowi][coli] = true;
  if (arr[rowi][coli] == 0) return;
  size += arr[rowi][coli];
  for (int i = -1; i < 2; i++) {
    for (int j = -1; j < 2; j++) {
      if (i+rowi >= 0 && i+rowi < row && j+coli >= 0 & j+coli < col) {
        if (!visited[rowi+i][coli+j]) DFS(arr, coli+j, rowi+i, visited, size);
      }
    }
  }
}

template <size_t col, size_t row>
void DfsIslands(int (&arr)[row][col]) {
  bool visited[row][col];
  for (int i = 0; i < col; i++) {
    for (int j = 0; j < row; j++) {
      visited[j][i] = false;
    }
  }
  for (int i = 0; i < col; i++) {
    for (int j = 0; j < row; j++) {
      if (!visited[j][i]) {
        int k = 0;
        DFS(arr, i, j, visited, k);
        if (k > 0) cout << k << " ";
      }
    }
  }
}


int main() {
  int arr[4][5] = {2,2,0,0,2,
                   1,0,0,1,1,
                   0,0,1,1,1,
                   1,1,1,1,1};
  DfsIslands(arr);
  return 0;
}
