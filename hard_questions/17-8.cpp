#include <iostream>
#include <vector>
#include <utility>

using namespace std;

vector<pair<int, int> > bestSeqAtIndex(vector<pair<int, int> > &arr, 
    vector<vector<pair<int, int> > > &sols, int index) {
  vector<pair<int, int> > best_seq;

  for (int i = 0; i < index; i++) {
    vector<pair<int, int> > sol = sols[i];
    if (arr[index].first < sol[sol.size()-1].first && 
        arr[index].second < sol[sol.size()-1].second) {
      if (sol.size() > best_seq.size()) best_seq = sol;
    }
  }
  best_seq.push_back(arr[index]);

  cout << endl;
  cout << endl;
  cout << endl;
  for (int i = 0; i < best_seq.size(); i++) cout << best_seq[i].first << " " <<
   best_seq[i].second << endl;
  cout << endl;
  cout << endl;
  cout << endl;

  return best_seq;
}

vector<pair<int, int> > longestSequence(vector<pair<int, int> > &arr) {
  vector<vector<pair<int, int> > > sols;
  vector<pair<int, int> > best_seq;

  for (int i = 0; i < arr.size(); i++) {
    vector<pair<int, int> > longest_at_ind = bestSeqAtIndex(arr, sols, i);
    sols.push_back(longest_at_ind);
    if (longest_at_ind.size() > best_seq.size()) best_seq = longest_at_ind;
  }
  for (int i = 0; i < best_seq.size(); i++) cout << best_seq[i].first << " " <<
   best_seq[i].second << endl;
  return best_seq;
}

int main() {
  vector<pair<int, int> > arr;
  arr.push_back(make_pair(1,1));
  arr.push_back(make_pair(2,2));
  arr.push_back(make_pair(5,5));
  arr.push_back(make_pair(0,0));

  vector<pair<int, int> > k = longestSequence(arr);
  cout << endl << endl;
  for (int i = 0; i < k.size(); i++) cout << k[i].first << " " << 
   k[i].second << endl;
  return 0;
}
