#include <stack>
#include <iostream>
#include <limits>

using namespace std;

struct el {
  int val;
  int prior;
};

class pqStack {
  stack<el> k;
  void frontHelper(int &max, int &val) {
    if (k.empty()) return;
    struct el temp = k.top();
    k.pop();
    if (temp.prior > max) {
      max = temp.prior;
    }
    frontHelper(max, val);
    if (temp.prior == max) { 
      val = temp.val;
    } else k.push(temp);
  }

 public:
  int front() {
    int max = numeric_limits<int>::min();
    int val = numeric_limits<int>::min();
    frontHelper(max, val);
    return val;
  }
  void pop() {
    k.pop();
  }
  void push(struct el a) {
    k.push(a);
  }
};

int main() {
  pqStack a;
  struct el k;
  k.val = 5;
  k.prior = 6;
  a.push(k);
  cout << a.front() << endl; 
  return 0;
}
