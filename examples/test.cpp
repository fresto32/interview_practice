#include <iostream>

#include <string>

using namespace std;

void fn(string *s) {
  s->push_back('k');
}

int main() {
  string k = "k";
  fn(&k);
  cout << k << endl;
  return 0;
}
