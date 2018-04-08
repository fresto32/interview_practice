#include <iostream>

using namespace std;

enum class label {nothing, cross, naught};

label ticTacWin(const label (&matrix)[3][3], int x = 0, int y = 0, 
    label row = label::naught, label col = label::naught, 
    label diag = label::naught, int row_c = 0,
    int col_c = 0, int diag_c = 0) {

  if (row_c == 3) return row;
  else if (col_c == 3) return col;
  else if (diag_c == 3) return diag;

  if ((x > 2) || (y > 2)) return label::nothing;

  if (matrix[y][x] != row) {
    row = matrix[y][x];
    row_c = 0;
  }
  if (matrix[y][x] != col) {
    col = matrix[y][x];
    col_c = 0;
  }
  if (matrix[y][x] != diag) {
    diag = matrix[y][x];
    diag_c = 0;
  }
  diag_c++;
  row_c++;
  col_c++;
  label R = ticTacWin(matrix, x+1, y, row, col, diag, row_c, col_c, diag_c);
  if (R != label::nothing) return R;
  label D = ticTacWin(matrix, x, y+1, row, col, diag, row_c, col_c, diag_c);
  if (D != label::nothing) return D;
  label Z = ticTacWin(matrix, x+1, y+1, row, col, diag, row_c, col_c, diag_c);
  if (Z != label::nothing) return Z;
  return label::nothing;
}

int main() {
  label matrix[3][3] = {label::cross, label::cross, label::cross, 
    label::naught, label::naught, label::naught, label::nothing, 
    label::nothing, label::nothing};
  label re = ticTacWin(matrix);
  string a;
  if (re == label::naught) a = "naught";
  else if (re == label::cross) a = "cross";
  else if (re == label::nothing) a = "nothing";
  cout << a << endl;
  return 0;
}
