#ifndef _STACK_H_
#define _STACK_H_

template<class T>
class Stack{
  struct node {
    T val;
    node* next;
  };
  
  node *top;
  size_t count;

 public:
  Stack() : count(0) {}
  ~Stack();
  void push(T val);
  void pop();
  T peek();

};

#endif
