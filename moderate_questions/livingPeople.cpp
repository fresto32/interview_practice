#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int livingPeople(vector<int> b, vector<int> d) {
  sort(b.begin(), b.end());
  sort(d.begin(), d.end());

  int max = 0;
  int max_y;
  int ind_d = 0;
  int current = 0;

  for (int i = 0; i < b.size(); i++) {
    current++;
    while (b[i] > d[ind_d]) {
      ind_d++;
      current--;
    }

    if (current > max) {
      max = current;
      max_y = b[i];
    }
  }
  return max_y;
}

int main() {
  vector<int> b;
  vector<int> d;

  b.push_back(1902);
  b.push_back(1915);
  b.push_back(1944);
  b.push_back(1950);

  d.push_back(1980);
  d.push_back(1945);
  d.push_back(1950);
  d.push_back(1990);

  cout << livingPeople(b, d) << endl;

  return 0;
}

