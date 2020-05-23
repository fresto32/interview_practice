#include <iostream>


int search(int a[], int left, int right, int x) {
  int mid = (left + right) / 2;
  if (x == a[mid]) return mid;
  if (right < left) return -1;

  if (a[left] < a[mid]) { //left is ordered
    if(x >= a[left] && x < a[mid])
      return search(a, left, mid-1, x);
    else 
      return search(a, mid+1, right, x);
    
  } else if (a[left] > a[mid]) { //right is ordered
    if (x > a[mid] && x <= a[right])  
      return search(a, mid+1, right, x);
    else 
      return search(a, left, mid-1, x);
    
  } else if (a[left] == a[mid]) { //left or right is repeating
    if (a[mid] != a[right]) { // right is different, search it
      return search(a, mid + 1, right, x);
    } else { // else search both
      int result = search(a, left, mid - 1, x);
      if (result == -1) return search(a, mid + 1, right, x);
      else return result;
    }
  }
  return -1;
}
    

int searchRotatedArray(int a[], int x, int n) {
  int low = 0;
  int hi = n - 1;
  while (low < hi) {
    int mid = (low + hi) / 2;
    if (!(a[mid] < a[hi])) low = mid + 1;
    else if (!(a[mid] > a[low])) hi = mid - 1;
    std::cout << "s1: " << mid << std::endl;
    std::cout << "hi: " << hi << " low: " << low << std::endl;
  }
  int shift = low;
  hi = shift;
  int lo = (shift + 1 >= n) ? 0 : shift + 1;
  while (true) {
    int mid = (hi + n - 1 + lo) / 2;
    if (a[mid] > x) lo = mid + 1;
    else if (a[mid] < x) hi = mid - 1;
    else return mid;
    std::cout << "s2" << std::endl;
  }
}


int main() {
  int arr[] = {6,1,2,3,4,5};
  std::cout << searchRotatedArray(arr, 5, 6) << std::endl;
  std::cout << search(arr, 0, 5, 5) << std::endl;
  return 0;
}
