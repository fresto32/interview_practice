// This algorithm runs in O(N log N) time by swapping indices in the optimal
// order. Note that this algorithm is faster than the CCI's because not all
// N^2 items are touched. Rather, only items that must be swapped are swapped.

#include <algorithm>
#include <iostream>

template <size_t rows, size_t cols>
void rotateMatrix(int (&matrix)[rows][cols]) {
  int i = 0, k = 0, j = 1;
  int n = rows - 1;

  while (n > i) {
    k = j;
    while (k <= n) {
      std::swap(matrix[i][k], matrix[k][i]);
      k++;
    }
    i++;
    j++;
  }
}

int main() {
  int matrix[6][6] = { {1,1,1,1,1,1}, {2,2,2,2,2,2}, {3,3,3,3,3,3}, 
    {4,4,4,4,4,4}, {5,5,5,5,5,5}, {6,6,6,6,6,6} };
  rotateMatrix(matrix);

  for (int i = 0; i < 6; i++) {
    std::cout << std::endl;
    for (int k = 0; k < 6; k++)
      std::cout << matrix[i][k] << ", ";
  }
  return 0;
}

