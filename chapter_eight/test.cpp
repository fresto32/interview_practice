#include <iostream>
#include <map>
#include <utility>

int main() {
  std::map<std::pair<int, int>, std::pair<int, int> > myMap;
  myMap[std::make_pair(0,0)] = std::make_pair(1,1);
  return 0;
}
