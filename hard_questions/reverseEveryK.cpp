#include <iostream>

using namespace std;

struct list {
  int val;
  struct list *next;
};

void reverseEveryK(struct list **h, int k) {
  struct list *start = (*h);
  struct list *curr = *h;
  struct list *prev = nullptr;
  struct list *prev_start = nullptr;
  struct list *next = nullptr;
  while (curr->next) {
    start = curr;
    cout << "start: " << start->val << endl;
    prev = nullptr;
    for (int i = 0; i < k; i++) {
      cout << "curr: " << curr->val << endl;
      next = curr->next;
      curr->next = prev;
      prev = curr;
      if (!next) break;
      curr = next;
    }
    if (!next) break;
    start->next = curr;
    cout << "start->next->val: " << start->next->val << endl;
  }
  cout << "returned" << endl;

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

