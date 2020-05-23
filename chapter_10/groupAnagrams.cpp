#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

string groupAnagrams(string a) {
  vector<string> words;
  int start = 0;
  for (int i = 0; i < a.size(); i++) {
    if((a[i] == ' ') || (i == a.size() - 1)) {
      if (i != a.size() - 1) words.push_back(a.substr(start, i-start));
      else words.push_back(a.substr(start,i-start+1));
      start = i + 1;
    }
  }

  unordered_map<string, vector<string> > anagrams;

  for (int i = 0; i < words.size(); i++) {
    string sorted = words[i];
    sort(sorted.begin(), sorted.end());
    anagrams[sorted].push_back(words[i]);
  }

  string results;

  for (unordered_map<string, vector<string> >::iterator it = anagrams.begin();
      it != anagrams.end(); it++) {
    for (int i = 0; i < (it->second).size(); i++)
      results += (it->second)[i] + " ";
  }
  return results;
}

int main() {
  string a = "silent to the listen ot place topple eplace pottle";

  std::cout << groupAnagrams(a) << std::endl;

  return 0;
}

