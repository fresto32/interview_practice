#include <iostream>

// Given two arrays of integers, compute the pair of values (one val in each)
// with the smallest (non-negative) difference, return the difference
//
// {1,3,8}, {15,81,10} return 2 that (10,8)
//
// Brute Force: Iterate through each element of one array against every el of 
//              the other array. -> keep min value variable
//              O(N^2) -> N longest array
//
// Sort First:  Sort each array. Then compare a[i] with b[i], b[i-1], b[i+1]
//              O(NlgN) -> N longest array
//
// Best Conceivable Runtime: Either find the diff between every el or sort?
//
// Data Structure: Tree: O(NlgN), {1-15, 3-81, 8-10}, n!
//

int smallestDifference(vector<int> a, vector<int> b) {
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  int smallest_difference = (abs(a[0]-b[0]) < abs(a[0]-b[1])) ? abs(a[0]-b[0]):
    abs(a[0]-b[1]);

  for (int i = 1; i < a.size(); i++) {
    if (abs(a[i] - b[i-1]) < smallest_difference) 
      smallest_difference = abs(a[i] - b[i-1]);
    if (abs(a[i] - b[i]) < smallest_difference) 
      smallest_difference = abs(a[i] - b[i]);
    if (i != a.size() -1) {
      if (abs(a[i] - b[i+1]) < smallest_difference) 
        smallest_difference = abs(a[i] - b[i+1]);
    }
  }

  return smallest_difference;
}

