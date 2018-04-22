#include <iostream>
#include <unordered_map>

using namespace std;

enum class color {R, G, Y, B};

typedef struct partial_answer {
  int hits;
  int pseudo;
} partial_answer;

partial_answer masterMind(color (*arr)[4], color (*guess)[4]) {
  unordered_map<int, int> m;

  for (int i = 0; i < 4; i++) {
    if (m.count((int)(*arr)[i])) {
      m[(int)(*arr)[i]]++;
    } else {
      m[(int)(*arr)[i]] = 1;
    }
  }

  int hits = 0, pseudo = 0;

  for (int i = 0; i < 4; i++) {
    if ((*arr)[i] == (*guess)[i]) {
      hits++;
      m[(int)(*arr)[i]]--;
    }
    else if (m.count((int)(*guess)[i])) 
      if (m[(int)(*guess)[i]] > 0) pseudo++;
  }
  partial_answer ans;
  ans.hits = hits;
  ans.pseudo = pseudo;
  return ans;
}

int main() {
  color soln[4] = {color::R, color::G, color::Y, color::B};
  color guess[4] = {color::R, color::G, color::G, color::G};

  partial_answer k;
  k = masterMind(&soln, &guess);
  cout << k.hits << " " << k.pseudo << endl;;
  cout << (int) color::R << " " << (int) color::Y;
  return 0;
}

