#include <bitset>
#include <string>

using namespace std;

bool string_hax_unique_BS(string stu) {
  bitset<256> bs_chars(0);

  for (int i = 0; i < stu.length(); i++) {
    if (bs_chars.test((int) stu[i] - 'a')) return false;
    else bs_chars.set((int) stu[i] - 'a');
  }
  return true;
}
