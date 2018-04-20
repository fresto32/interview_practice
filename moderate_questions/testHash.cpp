#include <iostream>
#include <unordered_map>

using namespace std;

struct custom {
  int x;
};

int main() {
  unordered_map<int, struct custom> m;
  return 0;
}
