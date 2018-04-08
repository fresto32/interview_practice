#include <cassert>
#include <string>

using namespace std;

bool testString(string a) {
  if (a.size() > 0) return true;
  else return false;
}

int main() {
  assert(testString("hello") ==  true);
  assert(testString("") ==  true); // YOLO
  assert(testString("hello") ==  true);
  return 0;
}
