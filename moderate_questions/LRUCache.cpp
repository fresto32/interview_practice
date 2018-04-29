#include <iostream>
#include <unordered_map>

using namespace std;

template <class T, class K>
class LRUCache {
  typedef struct list {
    T val;
    K key;
    list *next;
    list *prev;
  } list;

  unordered_map<K, list*> m;
  
  list *bottom;
  list *top;
  int max_size;
  int curr_size;

  void evict() {
    if (!bottom) return;
    list *ptr = bottom;
    bottom = bottom->next;
    m.erase(ptr->key);
    delete[] ptr;
  }

 public:
  void add(T value, K key_to_add) {
    if (curr_size >= max_size) evict();
    list *ptr = new list;
    ptr->val = value;
    ptr->key = key_to_add;
    ptr->prev = nullptr;
    ptr->next = bottom;
    bottom = ptr;
    m[key_to_add] = ptr;
    curr_size++;
    if (curr_size == 1) top = bottom;
  }

  T search(K key_to_search) {
    list *p = m[key_to_search];
    if (p->prev) p->prev->next = p->next;
    if (p->next) p->next->prev = p->prev;
    top->next = p;
    p->prev = top;
    p->next = nullptr;
    top = p;
    return p->val;
  }

  LRUCache(int _max_size) : max_size(_max_size), curr_size(0) {
    top = nullptr;
    bottom = nullptr;
  }

  ~LRUCache() {
    while (bottom != nullptr) {
      list *ptr = bottom;
      bottom = bottom->next;
      delete[] ptr;
    }
  }
};

int main() {
  LRUCache<int,int> c(3);
  c.add(3,3);
  c.add(2,2);
  c.add(1,1);

  cout << c.search(1) << endl;
  cout << c.search(2) << endl;
  cout << c.search(3) << endl;
  c.add(4,4);
  cout << c.search(4) << endl;
  return 0;
}
