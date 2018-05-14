#include <unordered_map>
#include <vector>
#include <iostream>
#include <utility>

using namespace std;

// O(Pairs + Names) function

unordered_map<string, int*> mapBuilder(unordered_map<string, int> &freq,
    vector<pair<string, string> > &syn) {
  unordered_map<string, int*> hash;

  for (int i = 0; i < syn.size(); i++) {
    string t1 = syn[i].first;
    string t2 = syn[i].second;
    if (!hash.count(t1) && !hash.count(t2)) {
      int *ptr = new int;
      *ptr = freq[t1] + freq[t2];
      hash[t1] = ptr;
      hash[t2] = ptr;
    } else if (!hash.count(t1) || !hash.count(t2)) {
      string contained = (hash.count(t1)) ? t1 : t2;
      string noncontained = (hash.count(t1)) ? t2 : t1;

      *hash[contained] += freq[noncontained];
      hash[noncontained] = hash[contained];
    } else {
      *hash[t1] += *hash[t2];
      hash[t2] = hash[t1];
    }
  }

  for (unordered_map<string, int>::iterator it = freq.begin(); 
      it != freq.end(); it++) {
    if (!hash.count(it->first)) {
      int *ptr = new int;
      *ptr = it->second;
      hash[it->first] = ptr;
    }
  }
  return hash;
}

int main() {
  // Testing 
  vector<pair<string, string> > syn;
  syn.push_back(make_pair("John", "Jon"));
  syn.push_back(make_pair("John", "J"));
  syn.push_back(make_pair("Jo", "Joe"));
  syn.push_back(make_pair("John", "Joe"));
  syn.push_back(make_pair("Miguel", "Mig"));

  unordered_map<string, int> freq;
  freq["John"] = 1;
  freq["Jon"] = 1;
  freq["J"] = 1;
  freq["Jo"] = 1;
  freq["Joe"] = 1;
  freq["Miguel"] = 2;
  freq["Mig"] = 2;
  freq["Taj"] = 1;

  unordered_map<string, int*> k = mapBuilder(freq, syn);

  string temp;
  while (true) {
    cin >> temp;
    cout << *k[temp] << endl;
  }
  return 0;
}

