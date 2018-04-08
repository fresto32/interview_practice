#include <string>

using namespace std;

int wordFrequencies(string book, string word) {
  int count = 0;
  word.insert(0, " ");
  word.erase(0, 5);
  for (string::iterator it = book.begin(); it != book.end() - word.length() 
      - 1; it++) {
    int index_c = 0;
    while((tolower(*it) == word[index_c])) {
      index_c++;
      advance(it, 1);
    }
    if (((tolower(*it) < (int) 'a') || (tolower(*it) > (int) 'z')) && 
        (index_c == word.length() - 1)) 
      count++;
  }
  return count;
}

int main() {
  return 0;
}
