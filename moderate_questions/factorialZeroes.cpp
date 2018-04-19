// Write an algorithm which computes the number of trailing zeroes in n 
// factorial
//
// 10! = num zeroes
// 1! = 1
// 2! = 2
// 3! = 6
// 4! = 24
// 5! = 120
// 6! = 720
// 8! = 5,760
// 9! = 51,840
// 10! = 518,400
// 15! = 000
// 20! = 0000
//
// Everytime 5, we add 0
// Everytime 10 we add 0
// if(num_0 % 5 == 0) num_0 += n/5;
// if(num_0 %10 == 0) num_0 += n/10;

int numZeroes(int n) {
  int num_0 = 0;

  if (n % 5 == 0) num_0 += n/5;
  if (n %10 == 0) num_0 += n/10;

  return num_0;
}

int numZeroes2(int n) {
  int count = 0;
  for (int i = 5; n / i > 0; i += 5) {
    count += n / i;
  }
  return count;
}

int main() {
  return 0;
}
