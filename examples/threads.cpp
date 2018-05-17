#include <thread>
#include <iostream>
#include <mutex>

using namespace std;

mutex th1_l;
void foo(int x) {
  th1_l.lock();
  for (int i = 0; i < x; i++) cout << "FOO1: " << i << endl;
  th1_l.unlock();
}

int foo2(int z) {
  th1_l.lock();
  for (int i = 0; i < z; i++) cout << "FOO2: " << i << endl;
  th1_l.unlock();
  return z;
}

int main() {
  thread th1(foo, 50);
  thread th2(foo, 20);


  th1.join();
  th2.join();
  return 0;
}



