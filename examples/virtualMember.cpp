#include <iostream>

class A {
  int k = 0;
 public:
  A() {}
};

class B : public A {
 public:
  B(int b) : b(k) {}
}

int main() {
  return 0;
}
