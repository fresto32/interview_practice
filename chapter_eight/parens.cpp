#include <vector>
#include <string>
#include <iostream>

using namespace std;

void parens(vector<string> *re, int n, int open, int 
    close, string prefix = "") {
  if (prefix.length() == 2*n) {
    re->push_back(prefix);
    return;
  } else {
    if (open > 0) parens(re, n, open - 1, close, prefix + '(');
    if (open < close) parens(re, n, open, close - 1, prefix + ')');
  }
}

int main() {
  vector<string> re;
  parens(&re, 4, 4, 4);

  for (int i = 0; i < re.size(); i++)
    cout << re[i] << endl;
  return 0;
}
