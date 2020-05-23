#include <iostream>

int fibonacci(int i) {
  if (i == 0) return 0;
  if (i == 1) return 1;
  return fibonacci(i-1) + fibonacci(i-2);
}

int fibonacci_memo(int i, int *memo) {
  if ((i==0) || (i==1)) return i;

  if (memo[i] == 0) {
    memo[i] = fibonacci_memo(i-1, memo) + fibonacci_memo(i-2, memo);
  }
  return memo[i];
}

int fibonacci2(int n) {
  int *ptr = new int[n+1];
  for (int i = 0; i < n + 1; i++) ptr[i] = 0;
  return fibonacci_memo(n, ptr);
}

int fibonacci_bottom_up(int n) {
  if (n == 0) return 0;
  else if (n == 1) return 1;

  int *memo = new int[n];
  memo[0] = 0;
  memo[1] = 1;
  for (int i = 2; i < n; i++) {
    memo[i] = memo[i-1] + memo[i-2];
  }
  return memo[n-1] + memo[n-2];
}

int fibonacci_bottom_up2(int n) {
  if (n == 0) return 0;
  else if (n == 1) return 1;
  int a = 0;
  int b = 1;
  
  for (int i = 2; i < n; i++) {
    int c = a + b;
    a = b;
    b = c;
  }
  return a + b;
}

int main() {
//  std::cout << fibonacci(50) << std::endl;
  int num;
  std::cin >> num;
  std::cout << fibonacci2(num) << std::endl;
  std::cout << fibonacci_bottom_up(num) << std::endl;
  std::cout << fibonacci_bottom_up2(num) << std::endl;
  return 0;
}
