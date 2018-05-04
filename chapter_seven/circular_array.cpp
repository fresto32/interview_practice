#include <iostream>

using namespace std;

template <class T>
class CircularArray {
  typedef struct node {
    T val;
    node* next;
  } node;
  node *head;
  node *tail;
  int length_list;
 public:
  CircularArray() : head(nullptr), tail(nullptr), length_list(0) {}

  void append(T value) {
    node *ptr = new node;
    ptr->val = value;
    if (!tail) {
      tail = ptr;
      head = ptr;
      ptr->next = ptr;
    } else {
      tail->next = ptr;
      ptr->next = head;
      tail = ptr;
    }
    length_list++;
  }

  void prepend(T value) {
    node *ptr = new node;
    ptr->val = value;
    if (!head) {
      tail = ptr;
      head = ptr;
      ptr->next = ptr;
    } else {
      ptr->next = head;
      head = ptr;
      tail->next = head;
    }
    length_list++;
  }

  void rotate(int shift) {
    if (shift < 0) shift += length_list;
    if (!head) exit(1);
    for (int i = 0; i < shift; i++) {
      head = head->next;
      tail = tail->next;
    }
  }

  void traverse() {
    node *crawl = head;
    for (int i = 0; i < length_list; i++) {
      cout << crawl->val << " ";
      crawl = crawl->next;
    }
    cout << endl;
  }
};

int main() {
  CircularArray<int> k;
  k.append(1);
  k.traverse();
  k.append(2);
  k.traverse();
  k.append(3);
  k.traverse();
  k.append(4);
  k.traverse();
  k.prepend(8);
  k.traverse();
  k.prepend(7);
  k.traverse();
  return 0;
}
