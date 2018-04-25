#include <iostream>

using namespace std;

template <size_t row, size_t col>
int pondSizeHelper(int (&arr)[row][col], int i, int k, int sz, 
    bool (&v)[row][col]) {
  v[i][k] = true;

  if (arr[i][k] == 0) sz++;
  else return sz;

  for (int a = -1; a <= 1; a++) {
    for (int b = -1; b <= 1; b++) {
      if (((a+i) >= 0) && ((b+k) < col)) {
        if(!(v[i+a][k+b])) {
          sz += (pondSizeHelper(arr, i + a, k + b, sz, v) - sz);
        }
      }
    }
  }
  return sz;
}

template <size_t row, size_t col>
void pondSize(int (&arr)[row][col]) {
  bool visited[row][col];

  for (int i = 0; i < row; i++) 
    for (int k = 0; k < col; k++)
      visited[i][k] = false;
  for (int i = 0; i < row; i++) {
    for (int k = 0; k < col; k++) {
      if (!visited[i][k]) {
        if (arr[i][k] == 0) {
          int size = pondSizeHelper(arr, i, k, 0, visited);
          cout << size << endl;
        } else {
          visited[i][k] = true;
        }
      }
    }
  }
}

int main() {
  int arr[][4] = {0,4,0,7,0,3,0,6,1,2,3,0,8,9,10,1};
  pondSize(arr);
  return 0;
}

  
