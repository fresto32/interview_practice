#include <bitset>
#include <iostream>

using namespace std;

void printMatrix(int (*matrix)[8][8]) {
  for (int i = 0; i < 8; i++) {
    for (int k = 0; k < 8; k++) {
      cout << (*matrix)[i][k] << " ";
    }
    cout << endl;
  }
  cout << endl << endl << endl;
}

void eightQueensHelper(int (*matrix)[8][8], bitset<10> *dp, bitset<10> *dn,
    bool (*rob)[8], int col);

void eightQueens(int (*matrix)[8][8]) {
  bitset<10> a(0);
  bitset<10> b(0);
  bool rob[8];
  for (int i = 0; i < 8; i++) rob[i] = false;
  eightQueensHelper(matrix, &a, &b, &rob, 0);
}

void eightQueensHelper(int (*matrix)[8][8], bitset<10> *dp, bitset<10> *dn,
    bool (*rob)[8], int col) {
  if (col >= 8) printMatrix(matrix);
  else {
    (*dp) <<= 1;
    (*dn) >>= 1;

    for (int i = 0; i < 8; i++) {
      if(!(*rob)[i] && !dp->test(i+1) && !dn->test(i+1)) {
        (*rob)[i] = true;
        dp->set(i+1);
        dn->set(i+1);
        (*matrix)[i][col] = 1;
        eightQueensHelper(matrix, dp, dn, rob, col + 1);
        (*dp) >>= 1;
        (*dn) <<= 1;
        (*matrix)[i][col] = 0;
        dn->reset(i+1);
        dp->reset(i+1);
        (*rob)[i] = false;
      }
    }
  }
}

int main() {
  int matrix[8][8] = {};
  printMatrix(&matrix);
  eightQueens(&matrix);
  return 0;
}
