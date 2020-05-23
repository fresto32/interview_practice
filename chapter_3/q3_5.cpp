#include <stack>
#include <iostream>

template <typename T>
void sortStack(std::stack<T> &one) {
  std::stack<T> two;

  int temp, counter, temp2, size_of_one;
  size_of_one = one.size();

  for (int i = 0; i < size_of_one; i++) {
    temp = one.top();
    one.pop();

    counter = 0;
    if (!two.empty()) {
       while (temp < two.top()) {
         one.push(two.top());
         two.pop();
         counter++;
    }
    }
    two.push(temp);
    for (int k = 0; k < counter; k++) {
      two.push(one.top());
      one.pop();
    }
  }
    while (!two.empty()) {
      one.push(two.top());
      two.pop();
    }
}

int main() {
  std::stack<int> one;
  std::cout << "Past initializer" << std::endl;
  for (int i = 20; i > 0; i--) one.push(i);
  std::cout << "Past pusher" << std::endl;
  sortStack(one);
  std::cout << "Past sorter" << std::endl;
  for (int i = 0; i < 20; i++) {
    std::cout << one.top() << std::endl;
    one.pop();
  }
  return 0;
}



