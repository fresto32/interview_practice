// Add without plus - write a function that adds two numbers without using
// + or any arithmetic operators
//
// Since I cannot use + / - / * / / -> bit manipulation?
//   0001
// + 0001
// = 0010
// if a.test[i] & b.test[i], shift left ?
// if a.test[i] | b.test[i], add together?
//
//   0010  
//  +0110  -> 1000
//  =1000
//
//   0111
//  +0001  -> 1000
//  =1000

#include <iostream>
#include <cassert>

using namespace std;

bool test(int num, int ind) {
  return ((num & (1 << ind)) != 0);
}

int set(int num, int ind) {
  return (num | (1 << ind));
}

int reset(int num, int ind) {
  return (num & ~(1 << ind));
}

int addWithoutPlus(int a, int b) {
  bool carry = false;
  int re = 0;
  for (int i = 0; i < 32; i++) {
    if (test(a,i) && test(b,i)) {
      carry = true;
    } else if (test(a,i) || test(b,i)) {
      if (!carry) re = set(re,i);
      else carry = false;
    } else if (carry) {
      carry = false;
      re = set(re,i);
    }
  }
  return re;
}

int add(int a, int b) {
  while (b != 0) {
    int sum = a ^ b; // add without carry
    int carry = (a & b) << 1; // carry, but don't add
    a = sum;
    b = carry;
  }
  return a;
}
//  0101
// +0101 -> 1100
// =1010
//
int main() {
  int a = 4;
  int b = 8;

  cout << addWithoutPlus(a,b) << endl;
  cout << addWithoutPlus(5,5) << endl;
  cout << add(5,5) << endl;
  cout << add(-2,-2) << endl;
  assert(addWithoutPlus(-2,-2) == -4);
  assert(addWithoutPlus(0,0) == 0);
  return 0;
}


