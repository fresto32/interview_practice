#include <iostream>
#include <vector>

using namespace std;

bool validate(vector<int> &k, int m) {
  int count = 0;
  for (int i = 0; i < k.size(); i++) {
    if (m == k[i]) count++;
  }
  return count > k.size()/2;
}

int majorityElement(vector<int> &k) {
  if (k.size() == 0) return -1;
  int to_match = k[0];
  int match = 0;
  int mismatch = 0;

  for (int i = 0; i < k.size(); i++) {
    if (to_match == k[i]) match++;
    else mismatch++;

    if (match <= mismatch) {
      match = 0;
      mismatch = 0;
      if (k.size() - 1 > i) to_match = k[i+1];
      else to_match = -1;
    }
  }
  if (to_match == -1) return -1;
  if (validate(k, to_match)) return to_match;
  else return -1;
}

int main() {
  vector<int> a;
  a.push_back(0);
  a.push_back(1);
  a.push_back(0);
  a.push_back(1);
  a.push_back(1);
  a.push_back(0);
  cout << majorityElement(a) << endl;
  return 0;
}
