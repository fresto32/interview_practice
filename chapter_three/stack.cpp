#include <iostream>
#include "stack.h"
#include <stdexcept>

template <typename T>
void Stack<T>::push(T val) {
  node *to_add = new node;
  to_add->val = val;

  // if the top is null, make top new node 
  if (top == nullptr) { 
    top = to_add;
    to_add->next = nullptr;
  }
  // else prepend to top
  else {
    to_add->next = top;
    top = to_add;
  }
  count++;
}

template <typename T>
void Stack<T>::pop() {
  // if the top is null throw an exception
  if (top == nullptr) throw std::runtime_error("Top is empty");
  // Else save top node and set top to next
  node *temp = top;
  top = temp->next;
  delete temp;
  count--;
}

template <typename T>
T Stack<T>::peek() {
  if (top == nullptr) throw std::runtime_error("Top is empty");
  return top->val;
}

template <typename T>
Stack<T>::~Stack() {
  node *current = top;

  while(count > 0) {
    pop();
    current = top;
    count--;
  }
}


int main() {
  char *k = "X";
  Stack<int> a;

  a.push(1);
  a.push(2);
  a.push(3);
  a.push(4);
  a.push(5);
  a.push(6);
  a.push(7);
  a.push(8);

  std::cout << a.peek() << std::endl;
  a.pop();
  std::cout << a.peek() << std::endl;
  a.pop();
  std::cout << a.peek() << std::endl;
  a.pop();
  std::cout << a.peek() << std::endl;
  a.pop();
  std::cout << a.peek() << std::endl;
  a.pop();
  std::cout << a.peek() << std::endl;
  a.pop();

  return 0;
}
