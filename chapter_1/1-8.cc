// I have the optimal time complexity, but a poor space complexity. This 
// problem can be solved in O(1) space.

#include <vector>
#include <iostream>

using namespace std;

template <size_t rows, size_t cols>
void zeroMatrix(int (&matrix)[rows][cols]) {
  vector<int> z_rows;
  vector<int> z_cols;

  z_rows.reserve(rows);
  z_cols.reserve(cols);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j ++) {
      if (matrix[i][j] == 0) {
        z_rows.push_back(i);
        z_cols.push_back(j);
      }
    }
  }

  int i = 0;

  while (z_rows.size() > 0) {
    i = z_rows.back();
    z_rows.pop_back();
    for (int j = 0; j < cols; j++) matrix[i][j] = 0;
  }

  while (z_cols.size() > 0) {
    i = z_cols.back();
    z_cols.pop_back();
    for (int j = 0; j < rows; j++) matrix[j][i] = 0;
  }
}

int main() {
  int matrix[][2] = { {1,1}, {0,1} };

  zeroMatrix(matrix);

  for (int i = 0; i < 2; i++) {
    cout << endl;
    for(int j = 0; j < 2; j++) cout << matrix[i][j];
  }

  return 0;
}
