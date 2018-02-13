#include <bitset>
#include <string>
#include <array>
#include <iostream>
#include <iterator>

using namespace std;

bool string_has_unique_chars(string stu) {
  array<bool, 256> char_hash;
  char_hash.fill(false);

  for (int i = 0; i < stu.length(); i++) {
    if (char_hash[(int) stu[i]] != false) {
      return false;
    } else char_hash[(int) stu[i]] = true;
  }
  return true;
}

bool string_has_unique_BS(string stu) {
  bitset<256> bs_chars(0);

  for (int i = 0; i < stu.length(); i++) {
    if (bs_chars.test((int) stu[i])) return false;
    else bs_chars.set((int) stu[i]);
  }
  return true;
}

bool string_has_unique_noDS(string stu) {
  for (int i = 0; i < stu.length(); i++) {
    for (int k = 0; k < stu.length(); k++) {
      if ((i != k) && (stu[i] == stu[k])) return false;
    }
  }
  return true;
}

int main() {
  array<string, 5> str = {"Taaj", "Taj", "Aa", "Yolo", "FOOR"};
 
  for (auto i = str.begin(); i != str.end(); i++) { 
  cout << " String One\n";
  cout << "No BS: " << string_has_unique_chars(*i) << "\n";
  cout << "BS: " << string_has_unique_BS(*i) << "\n";
  cout << "No DS: " << string_has_unique_noDS(*i) << "\n";
  }
  return 0;
}
