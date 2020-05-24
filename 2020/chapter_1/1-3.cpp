#include <cassert>
#include <iostream>

void urlify(char* raw, int length)
{
  if (length <= 2) return;

  int posLastLetter = length - 1;
  while (raw[posLastLetter] == ' ' || raw[posLastLetter] == '\0') posLastLetter--;

  for (int i = posLastLetter, j = length - 2; i >= 0, j >= 0; i--, j--) {
    char c = raw[i];
    if (c == ' ') {
      raw[j] = '0';
      raw[--j] = '2';
      raw[--j] = '%';
    } else {
      raw[j] = c;
    }
  }
}


int main() 
{
  char word[] = "He l lo                        ";
  urlify(word, 20);
  for (int i = 0; i < 20; i++) std::cout << word[i];
}