#include <iostream>
#include <unordered_map>

using namespace std;

int coins(float n, float sum = 0) {
  if (sum == n) return 1;
  else if (sum > n) return 0;
  else {
    return coins(n, sum + 0.25) + coins(n, sum + 0.10) +
           coins(n, sum + 0.05) + coins(n, sum + 0.01);
  }
}

int coins2(float n, unordered_map<float, int> *m, float sum = 0) {
  if (sum == n) return 1;
  else if (sum > n) return 0;
  else {
    if(!(m->count(sum+0.25))) (*m)[sum+0.25] = coins2(n, m, sum + 0.25);
    if(!(m->count(sum+0.10))) (*m)[sum+0.10] = coins2(n, m, sum + 0.10);
    if(!(m->count(sum+0.05))) (*m)[sum+0.05] = coins2(n, m, sum + 0.05);
    if(!(m->count(sum+0.01))) (*m)[sum+0.01] = coins2(n, m, sum + 0.01);

    return (*m)[sum+0.25] + (*m)[sum+0.10] + (*m)[sum+0.05] + (*m)[sum+0.01];
  }
}

int main() {
  float num;

  cin >> num;

//  cout << coins(num) << endl;
  
  unordered_map<float, int> m;

  cout << coins2(num, &m) << endl;

  return 0;
}
