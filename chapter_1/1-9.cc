#include <iostream>
#include <array>

using namespace std;

bool stringRotation(char *s1, char *s2) {
  array<int, 256> chars;
  chars.fill(0);

  int prev;
  int num_discrep = 1;
  for (int i = 0; i < strlen(s1); i++) {
    if (chars[s1[i]] == -1) num_discrep++;
    else if (chars[s1[i]] != 0) {
      num_discrep = num_discrep + 2;
      chars[s1[i]] = -1;
    } else chars[s1[i]] = i + 1;
  }

  for (int i = 0; i < strlen(s2); i++) {
    if (chars[s2[i]] == 0) return false;
    else if (i == 0) prev = chars[s2[i]];
    else if (chars[s2[i]] != prev + 1) {
      if (num_discrep == 0) return false;
      else {
        num_discrep--;
        prev = chars[s2[i]];
      }
    } else prev = chars[s2[i]];
  }
  return true;
}

int main() {
  char a[] = "wateraaaa";
  char b[] = "teraaaawa";

  cout << "StringRotation: " << stringRotation(a,b);

  return 0;
}
