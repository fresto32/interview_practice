#include <iostream>
#include <stack>

using namespace std;

template <class T>
typedef struct instruction {
  T val;
} instruction;

int main() {
  stack<struct instruction> k;
  return 0;
}
