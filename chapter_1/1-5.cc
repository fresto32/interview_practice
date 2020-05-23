#include <bitset>
#include <iostream>
#include <cstring>
#include <math.h>
#include <stdio.h>

using namespace std;

void setBs(bitset<256> bs, char *a) {
  for (int i = 0; i < strlen(a); i++) {
    if (bs.test(a[i])) bs.reset(a[i]);
    else bs.set(a[i]);
  }
}

bool oneAway(char *a, char *b) {
  int num_odd = fabs((strlen(a) - strlen(b)));
  if (num_odd > 1) return false;

  bitset<256> hash_chars(0);

  setBs(hash_chars, a);
  setBs(hash_chars, b);

  for (int i = 0; i < 256; i++) {
    if (hash_chars.test(i)) num_odd--;
    if (num_odd < 0) return false;
  }
  return true;
}

int main() {
  char a[] = "pale";
  char b[] = "ale";

  cout << oneAway(a, b);

  return 0;
}
