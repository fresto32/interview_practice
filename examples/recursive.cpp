#include <iostream>

// Tail recursion to speed up function
double func(int i, double sum = 0) {
  if (i == 0) return sum;
  else return func(i-1, sum + ( (double) i /(i+1)));
}

// Tail recusion again
long sumDigits(long n, long sum = 0) {
  if (n == 0) return 0;
  else return sumDigits(n/10, sum + n%10);
}

int main() {
  std::cout << func(2) << std::endl;
  return 0;
}
