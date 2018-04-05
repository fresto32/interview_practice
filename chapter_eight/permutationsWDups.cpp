#include <unordered_map>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

void permutations(unordered_map<char, int> *h, int length, vector<string> *re,
    string prefix = "") {
  if (prefix.length() == length) {
    re->push_back(prefix);
    return;
  } else {
    for (unordered_map<char, int>::iterator it = h->begin(); it != h->end();
        it++) {
      if (it->second > 0) {
        it->second--;
        permutations(h, length, re, prefix + it->first);
        it->second++;
      }
    }
  }
}

int main() {
  vector<string> results;
  string ava = "12345678";
  unordered_map<char, int> ava_m;
  ava_m['a'] = 1;
  ava_m['b'] = 2;
  permutations(&ava_m, 3, &results);

  for (int i = 0; i < results.size(); i++)
    cout << results[i] << endl;
  return 0;
}
