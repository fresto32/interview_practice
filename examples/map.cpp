#include <map>
#include <iostream>

using namespace std;

struct container {
  int k;
  int b;
};

int main() {
  struct container a;
  a.k = 5;
  a.b = 6;

  map<int, struct container> m;
  m[1] = a;

  return 0;
}
