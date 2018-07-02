#include <iostream>

string add(string &a, string &b) {
  int index_a = a.size() - 1;
  int index_b = b.size() - 1;
  int carry = 0;
  string output;
  while (index_a >= 0 && index_b >= 0) {
    int total_sum = stoi(a[index_a]) + stoi(b[index_b]) + carry;
    if (total_sum >= 10) carry = 1;
    else carry = 0;
    output += tostring(total_sum % 10);
  }
  if (carry) output += "1";
  reverse(output.begin(), output.end());

  return output;
}

string subtract(string &a, string &b) {
  // a >= b
  string output;

