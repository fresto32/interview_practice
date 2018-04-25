#include <iostream>

using namespace std;

template <size_t row, size_t col>
void funct(int (&matrix)[row][col]) {
  cout << matrix[0][0] << endl;
}

int main() {
  int matrix[][2] = {2,3,2,3};
  funct(matrix);
  return 0;
}

