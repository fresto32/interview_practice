#include <string>
#include <vector>
#include <iostream>

std::vector<std::vector<int> > powerSet(std::vector<int> set, int index) {
  std::vector<std::vector<int> > *all_subsets = 
    new std::vector<std::vector<int> >;
  // For n = 1, the subsets are {} and {1}
  if (set.size() == index) {                    // Base Case - add empty set
    std::vector<int> *empty_set = new std::vector<int>;
    all_subsets->push_back(*empty_set);           // Empty set
  } else { 
    *all_subsets = powerSet(set, index + 1);
    int item = set[index];
    std::vector<std::vector<int> > *more_subsets = 
      new std::vector<std::vector<int> >;
    for (auto i = all_subsets->begin(); i != all_subsets->end(); i++) {
      std::vector<int> *new_subset = new std::vector<int>;
      new_subset->insert(new_subset->begin(), i->begin(), i->end());
      for (int k = 0; k < i->size(); k++)
        i->at(k) = i->at(k) + item;
      more_subsets->push_back(*new_subset);
    }
    all_subsets->insert(all_subsets->begin(), more_subsets->begin(), 
        more_subsets->end());
  }
  return *all_subsets;
}

inline bool getBit(int k, int i) {
  return ((k & (1 << i)) != 0);
}

std::vector<int> convertIntToSet(std::vector<int> set, int k) {
  std::vector<int> to_return;

  for (int i = 0; i < set.size(); i++) {
    if (getBit(k, i)) to_return.push_back(set[i]);
  }
  return to_return;
}

std::vector<std::vector<int> > powerSets2(std::vector<int> set) {
  std::vector<std::vector<int> > all_subsets;
  int max = 1 << set.size(); // finds 2^n
  
  for (int k = 0; k < max; k++) {
    all_subsets.push_back(convertIntToSet(set, k));
  }
  return all_subsets;
}


int main() {
  std::vector<int> test;
  test.push_back(1);
  test.push_back(2);
  test.push_back(3);
  test.push_back(4);

  std::vector<std::vector<int> > test2;
  
  test2 = powerSets2(test);
  
  std::cout << "SIZE: " << test2.size() << std::endl;

  for (int i = 0; i < test2.size(); i++) {
    for (int j = 0; j < test2[i].size(); j++) {
      std::cout << test2[i][j] << " ";
    }
    std::cout << std::endl;
  }


  return 0;
}
