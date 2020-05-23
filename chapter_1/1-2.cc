#include <array>
#include <string>
#include <iostream>

using namespace std;

bool string_is_permutation(string perm_str, string parent_str, bool flag) {
  array<int, 256> char_hash;
  char_hash.fill(0);

  if ((parent_str.length() == 0) || (perm_str.length() == 0)) {
    cout << "String(s) are empty!\n";
    return false;
  }

  for (int i = 0; i < perm_str.length(); i++) char_hash[perm_str[i]]++;

  for (int i = 0; i < parent_str.length(); i++) {
    char_hash[parent_str[i]]--;

    if (char_hash[parent_str[i]] < 0) {
      if (flag) return string_is_permutation(parent_str, perm_str, false);
      else return false;
    }
  }
  return true;
}

int main() {
  cout << "Value: " << string_is_permutation("Hell", "ello", true);

  return 0;
}
