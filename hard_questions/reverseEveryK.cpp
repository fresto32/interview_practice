#include <iostream>

using namespace std;

struct list {
  int val;
  struct list *next;
};

void reverseEveryK(struct list **h, int k) {
  struct list *start = (*h);
  struct list *curr = *h;
  struct list *prev = (*h);
  struct list *prev_start = nullptr;
  struct list *next = nullptr;
  while (curr->next) {
    start = curr;
    for (int i = 0; i < k; i++) {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      if (!next) break;
      curr = next;
    }
    if (prev_start) {
      prev_start->next = prev;
    } else {
      (*h) = prev;
    }
    prev_start = start;
    if (!next) break;
    start->next = curr;
    prev = nullptr;
  }
  curr = (*h);
  for (int i = 0; i < 4; i++) {
    cout << curr->val << endl;
    curr = curr->next;
  }

}

int main() {
  struct list a;
  struct list b;
  struct list c;
  struct list d;
  a.next = &b;
  a.val = 1;
  b.next = &c;
  b.val = 2;
  c.next = &d;
  c.val = 3;
  d.next = nullptr;
  d.val = 4;

  struct list *ptr = &a;
  reverseEveryK(&ptr, 2);
  
  list curr = a;
//  for (int i = 0; i < 4; i++) {
//    cout << curr.val << endl;
//    if (i < 3) curr = *curr.next;
//  }
  return 0;
}

