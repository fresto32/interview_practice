#include <vector>
#include <string>
#include <iostream>

using namespace std;

void permutations(vector<string> *re, string ava, string prefix = "") {
  if (ava.length() == 0) {
    re->push_back(prefix);
    return;
  } else {
    for (int i = 0; i < ava.length(); i++) {
      string to_send = prefix + ava[i];
      string new_ava = ava;
      new_ava.erase(i, 1);
      permutations(re, new_ava, to_send);
    }
  }
}

int main() {
  vector<string> results;
  string ava = "12345678";
  permutations(&results, ava);

  for (int i = 0; i < results.size(); i++)
    cout << results[i] << endl;
  return 0;
}
