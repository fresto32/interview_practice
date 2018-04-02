#include <bitset>
#include <iostream>
#include <cmath>
#include <fstream>

unsigned int missingInt(unsigned int a[], unsigned int n) {
  std::bitset<4900000> bits(0);
  std::ifstream inFile;
  
  inFile.open("x.txt");
  int x;
  while(inFile >> x) {
    ...
  }

  for (unsigned int i = 0; i < n; i++)
    bits.set(a[i]);
  unsigned int index = 0;

  while (bits.test(index)) index++;
  return index;
}

int main() {
  unsigned int a[] = {0, 1,2,3,5,6};
  std::cout << missingInt(a, 6) << std::endl;
  return 0;
}
