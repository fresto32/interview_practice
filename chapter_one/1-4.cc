#include <bitset>
#include <cstring>
#include <iostream>

using namespace std;

bool is_palindrome_permutation(char *s) {
  if (strlen(s) == 0) {
    cout << "String 0\n"; 
    return false;
  }

  bitset<256> hash_bs(0);
  int size_of_s = 0;

  for (int i = 0; i < strlen(s); i++) {
    if (s[i] != ' ') {
      size_of_s++;
      if (hash_bs.test(tolower(s[i]))) hash_bs.reset(tolower(s[i])); 
      else hash_bs.set(tolower(s[i]));
    }
  }

  bool odd = false;
  if (size_of_s % 2 == 1) odd = true;

  for (int i = 0; i < 256; i++) {
    if (hash_bs.test(i)) {
      if (odd) odd = false;
      else return false;
    }
  }

  return true;
}

int main() {
  char palin[] = "T acocat";
  cout << "Result: " << is_palindrome_permutation(palin);

  return 0;
}

