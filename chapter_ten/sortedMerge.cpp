#include <iostream>
#include <string>
#include <unordered_map>

void sortedMerge(int a[], int b[], int na, int nb) {
  for (int i = nb; i < na; i++) a[i] = a[i-nb];

  int bi = 0;
  int ai = 0;

  for (int i = 0; i < na; i++) {
    if (bi < nb) {
      if (a[ai+nb] < b[bi]) {
        a[i] = a[ai+nb];
        ai++;
      } else {
        a[i] = b[bi++];
      }
    }
  }
}

int main() {
  int a[] = {4,5,6,0,0,0};
  int b[] = {1,2,3};

  sortedMerge(a, b, 6, 3);

  for (int i = 0; i < 6; i++)
    std::cout << a[i] << std::endl;

  return 0;
}
