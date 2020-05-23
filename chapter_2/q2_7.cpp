#include <unordered_map>
#include <iostream>

struct list {
  int val;
  list *next;
};

void addList(list *head,int value) {
  list *add = new list;
  add->val = value;
  add->next = head->next;
  head->next = add;
}

list *intersection(list *a, list *b) {
  std::unordered_map<list*, bool> hash;

  while (a != NULL) {
    hash.insert(a, true);
    a = a->next;
  }

  while ((hash.count(b) == 0) && (b != NULL)) {
    hash.insert(b,true);
    b = b->next;
  }

  if (hash.count(b) > 0) return b;
  else return NULL;
}

