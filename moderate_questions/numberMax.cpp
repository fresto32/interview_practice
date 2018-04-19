#include <iostream>

int flip(int bit) {
  return 1^bit;
}

int sign(int a) {
  return flip((a >> 31) & 1);
}

int max(int a, int b) {
  int k = sign(a-b);
  int q = flip(k);
  return a * k + b * q;
}

int main() {
  std::cout << max(5,3) << std::endl;
  std::cout << max(3,5) << std::endl;
  return 0;
}
