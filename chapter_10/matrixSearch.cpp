#include <iostream>

template <size_t rows, size_t cols>
bool sortedMatrix(int (&a)[rows][cols], int row, int col, int x) {
  int rowi = 0;
  int coli = col - 1;

  while((rowi < row - 1) && (coli >= 0)) {
    if (a[rowi][coli] == x) return true;
    else if (a[rowi][coli] > x) coli--;
    else rowi++;
  }
  return false;
}

int main() {
  int arr[4][4] = {1,2,3,5,4,5,6,7,5,6,8,10,7,8,9,12};

  std::cout << sortedMatrix(arr, 4, 4, 8) << std::endl;
  return 0;
}
