#include <vector>
#include <iostream>
#include <unordered_map>

struct list {
  int val;
  list *next;
};

bool isPalindrome(list *a) {
  list *head = a;
  list *head2 = a;
  int length = 0;

  while((a != NULL) && (a->next != NULL) && (a->next->next != NULL)) {
    a = a->next->next;
    length += 2;
  }
  if (a == NULL) length--;
  if (a->next != NULL) length++;
  std::vector<int> stack;

  for (int i = 0; i <= length; i++) {
    stack.push_back(head->val);
    head = head->next;
  }

  for (int i = 0; i <= length/2; i++) {
    if (head2->val != stack.back()) return false;
    head2 = head2->next;
    stack.pop_back();
  }
  return true;
}

bool recursPalindrome(list *&left, list *right) {
  if (right == NULL) return true;

  bool isPalindromeBool = recursPalindrome(left, right->next);
  if (!isPalindromeBool) return false;

  isPalindromeBool = (left->val == right->val);

  left = left->next;

  return isPalindromeBool;
}

int main() {
  list *a = new list;
  a->val = 1;
  a->next = NULL;

  list *b = new list;
  b->val = 2;
  b->next = NULL;
  a->next = b;

  list *c = new list;
  c->val = 1;
  c->next = NULL;
  b->next = c;

  std::cout << "result: " <<  isPalindrome(a) << std::endl;
  std::cout << "result: " <<  recursPalindrome(a,a);

  return 0;
}
