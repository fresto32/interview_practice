#include <string>
#include <iostream>

using namespace std;

void Urlify(char *url, int url_size) {
  int spaces = 0;
  for (int i = 0; i < url_size; i++) if (url[i] == ' ') spaces++;

  int s = url_size + 2*spaces - 1;
  int j = url_size - 1;

  while (j >= 0) {
    if (url[j] != ' ') url[s] = url[j];
    else {
      url[s] = '0';
      url[--s] = '2';
      url[--s] = '%';
    }
    s--;
    j--;
  }
}

int main() {
  char str[] =  "T aj                          ";
  Urlify(str, 4);
  cout << str;

  return 0;

}
