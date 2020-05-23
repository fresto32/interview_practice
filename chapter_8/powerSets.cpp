#include <string>
#include <vector>
#include <iostream>

using namespace std;

void powerSet(string input, vector<string> prefix, vector<string> *results){
  if (input.length() == 0) {
    *results = prefix;
    return;
  }

  for (int i = 0; i < input.length(); i++) {
    vector<string> temp_pre;
    string temp = input;
    temp.erase(temp.begin() + i);
    temp_pre = prefix;
    
    for (int j = 0; j < prefix.size(); j++)
      if (i != j) temp_pre.push_back(prefix[j] + input[i]);

    if (temp_pre.size() == 0)
      for (int k = 0; k < input.size(); k++) {
        string s;
        s.push_back(input[k]);
        temp_pre.push_back(s);
      }

    powerSet(temp, prefix, results);
    powerSet(temp, temp_pre, results);
  }
}

int main() {
  vector<string> *results = new vector<string>;
  results->reserve(10000);
  vector<string> prefix;
  string input = "123456789";

  powerSet(input, prefix, results);
  std::cout << results->size() << std::endl;
  for (int i = 0; i < results->size(); i++)
    std::cout << results->at(i) << std::endl;
  return 0;
}
