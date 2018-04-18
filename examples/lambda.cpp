#include <iostream>

int main() {
  int k = [](int first, int second) { return first + second; }(4,4);
  int y = []{ return 3+3; }();
  std::cout << k << std::endl;
  std::cout << y << std::endl;

  return 0;
}
