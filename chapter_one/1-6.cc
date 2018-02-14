// Although convoluted, the following algorithm runs in O(n*k) where n is the
// length of the string passed into string_compression and k is the maximum 
// number of repititions made. I.e. for the input: 'accc' k is three. Thus, 
// using cstring allows for faster time complexity compared to std::string 
// where runtime is O(n^2) due to expensive concatenation. 
//
// An unfortunately tradeoff for the following algorithm is the use of a
// 'buffer' character array, which is not needed by the std::string algorithm.

#include <iostream>
#include <cstring>

using namespace std;

char *string_compression(char *s) {
  if (strlen(s) == 0) return NULL; 

  char str[strlen(s)];
  int str_index = 0;

  bool has_repitition = false;
  int counter = 0;
  char current_char[2];

  for (int i = 0; i < strlen(s) + 1; i++) {

    if (counter == 0) {
      current_char[0] = s[i];
      counter++;
    } else if ((i > 0) && (s[i-1] == s[i])) {
      counter++;
      has_repitition = true;
    } else {
      if (counter == 1)
          str[str_index++] = current_char[0];
      else {
        str[str_index++] = current_char[0];
        while (counter != 0) {
          str[str_index++] = '0' + counter % 10;
          counter /= 10; 
        }
      }
      counter = 0;
      current_char[0] = s[i];
      counter++;
    }
  }

  if (has_repitition) {
    char *str2 = new char[str_index];
    for (int i = 0; i < str_index; i++) { 
      str2[i] = str[i];
    }
    str2[str_index] = '\0';

    return str2;
  } else return s;
}

int main() {
  char a[] = "aabbbccd";
  cout << "A compressed is: " << string_compression(a);

  return 0;
}

