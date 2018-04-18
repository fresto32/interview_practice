#include <thread>
#include <iostream>

using namespace std;

void foo(int x) {
  for (int i = 0; i < x; i++) cout << "FOO1: " << i << endl;
}

int foo2(int z) {
  for (int i = 0; i < z; i++) cout << "FOO2: " << i << endl;
  return z;
}

int main() {
  thread th1(foo, 50);
  thread th2(foo2, 20);

  th1.join();
  th2.join();
  return 0;
}



