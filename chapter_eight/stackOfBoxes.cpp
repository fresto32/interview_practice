#include <iostream>
#include <vector>

using namespace std;

typedef struct box {
  int h;
  int w;
  int d;
} box;

void stackOfBoxes(vector<box> *b, int *maxh, box top, int height) {
  if (b->size() == 0) {
    if (height > *maxh) *maxh = height;
  } else {
    for (int i = 0; i < b->size(); i++) {
      if (((*b)[i].h < top.h) && ((*b)[i].w < top.w) && ((*b)[i].d < top.d)) {
        box curr = (*b)[i];
        box new_top = (*b)[i];
        b->erase(b->begin() + i);
        stackOfBoxes(b, maxh, new_top, height + new_top.h);
        b->insert(b->begin() + i, curr);
      }
    }
  }
}

int main() {
  box a;
  a.h = 5;
  a.w = 5;
  a.d = 5;

  box b;
  b.h = 4;
  b.w = 4;
  b.d = 4;

  box c;
  c.h = 3;
  c.w = 3;
  c.d = 3;

  vector<box> v;
  v.push_back(a);
  v.push_back(b);
  v.push_back(c);
  
  int max = 0;
  
  box d;
  d.h = 1000;
  d.w = 1000;
  d.d = 1000;

  stackOfBoxes(&v, &max, d, 0);

  cout << max << endl;


  return 0;
}
       
