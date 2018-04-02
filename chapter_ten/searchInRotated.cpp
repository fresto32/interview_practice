#include <iostream>

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
  return 0;
}
