#include <iostream>
#include <vector>

using namespace std;

int sequence(const vector<int> &a) {
  int max = 0;
  int current = 0;

  for (int i = 0; i < a.size(); i++) {
    current += a[i];
    if (current > max) max = current;
    if (current < 0) current = 0;
  }
  return max;
}

int main() {
  const int a[] = {2,-8,3,-2,4,-10, 1,1,11111};
  vector<int> b (a, a + sizeof(a)/sizeof(a[0]));
  cout << sequence(b) << endl;
  return 0;
}
