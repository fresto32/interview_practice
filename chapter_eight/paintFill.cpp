#include <iostream>

using namespace std;

template <size_t row, size_t col>
void paintFillHelper(int (*matrix)[row][col], int oc, int nc, int x, int y) {
  if ((*matrix)[x][y] == oc) (*matrix)[x][y] = nc;
  else return;

  for (int i = -1; i < 2; i++) {
    for (int k = -1; k < 2; k++) {
      if (((k != 0) || (i != 0)) && (i + x < row) && (y + k < col)) {
        paintFillHelper(matrix, oc, nc, x+i, y+k);
      }
    }
  }
}

template <size_t row, size_t col>
void paintFill(int (*matrix)[row][col], int nc, int x, int y) {
  int oc = (*matrix)[x][y];
  paintFillHelper(matrix, oc, nc, x, y);
}

int main() {
  int arr[4][4] = {2,2,1,1,8,1,1,1,1,1,1,1,1,7,5,4};

  paintFill(&arr, 9, 2, 1);

  for (int i = 0; i < 4; i++) {
    for (int k = 0; k < 4; k++) {
      cout << arr[i][k] << " ";
    }
    cout << endl;
  }
  return 0;
}
