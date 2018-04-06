#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <initializer_list>
#include <cmath>

using namespace std;

float DTWdistance(const vector<int> &a, const vector<int> &b) {

  float matrix[a.size()+1][b.size()+1];

  for (int i = 0; i < a.size(); i++)
    matrix[i][0] = numeric_limits<float>::max();
  for (int i = 0; i < b.size(); i++)
    matrix[0][i] = numeric_limits<float>::max();

  matrix[0][0] = 0;

  for (int i = 0; i < a.size(); i++) {
    for (int k = 0; k < b.size(); k++) {
      float dist = pow((a[i]-b[i]), 2);
      matrix[i+1][k+1] = dist + min({matrix[i][k+1], matrix[i+1][k], 
          matrix[i][k]});
    }
  }
  return pow(matrix[a.size()][b.size()], 0.5);
}

int main() {
  vector<int> a;
  a.push_back(5);
  a.push_back(3);
  a.push_back(4);
  a.push_back(5);
  a.push_back(7);
  a.push_back(8);
  a.push_back(9);

  vector<int> b;
  b.push_back(9);
  b.push_back(8);
  b.push_back(4);
  b.push_back(5);
  b.push_back(7);
  b.push_back(1);
  b.push_back(2);

  cout << DTWdistance(a, b) << endl;
  return 0;
}
