#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>
#include <limits>

using namespace std;

int getMax(const vector<int> &a) {
  int max = numeric_limits<int>::min();
  for (int i = 0; i < a.size(); i++) if (a[i] > max) max = a[i];
  return max;
}

int getMin(const vector<int> &a) {
  int min = numeric_limits<int>::max();
  for (int i = 0; i < a.size(); i++) if (a[i] < min) min = a[i];
  return min;
}

pair<int, int> subSort(const vector<int> &arr) {
  unordered_map<int, int> m;
  int mx = getMax(arr);
  int mn = getMin(arr);

  for (int i = 0; i < arr.size(); i++) {
    if (!m.count(arr[i])) m[arr[i]] = i;
  }
  int count = 0, prev = 0;
  
  for (int i = mn; i <= mx; i++) {
    if (i == arr[count]) {
      prev = i;
      count++;
    } else {
      m[i] = prev;
    }
  }
  
  int start;
  for (int i = 0; i < arr.size() - 1; i++) {
    if (arr[i] > arr[i+1]) {
      start = m[arr[i+1]];
      break;
    }
  }
  
  m.clear();
  for (int i = arr.size()-1; i >= 0; i--) {
    if (!m.count(arr[i])) m[arr[i]] = i;
  }
  count = arr.size() - 1;
  for (int i = mx; i >= mn; i--) {
    if (i == arr[count]) {
      prev = i;
      count--;
    } else {
      m[i] = prev;
    }
  }
  
  int end;
  for (int i = arr.size() - 1; i > 0; i--) {
    if (arr[i] < arr[i-1]) {
      cout << "start: " << m[arr[i]] << " arr[i] = " << arr[i] << endl;
      end = m[arr[i+1]];
      break;
    }
  }
  return make_pair(start, end);
}

int main() {
  static const int arr[] = {1,2,4,7,10,11,7,12,6,7,16,18,19};
  vector<int> a (arr, arr + sizeof(arr)/sizeof(arr[0]));
  pair<int, int> k = subSort(a);
  cout << get<0>(k) << " " << get<1>(k) << endl;
  return 0;
}
