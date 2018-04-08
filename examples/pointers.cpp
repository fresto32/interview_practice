#include <iostream>
#include <vector>

using namespace std;

void n1(int &n) {
  n += 1;
}

void n2(int *n) {
  *n += 1;
}

void n3(int n) {
  n += 1;
}

void add(vector<int> &n) {
  n.push_back(2);
  if (n.size() < 10) add(n);
}

int main() {
  int k = 0;
  n1(k);
  std::cout << k << std::endl;
  n2(&k);
  std::cout << k << std::endl;
  n3(k);
  std::cout << k << std::endl;

  vector<int> re;

  add(re);

  for (int i = 0; i < re.size(); i++) cout << re[i] << ", ";

  return 0;
}
