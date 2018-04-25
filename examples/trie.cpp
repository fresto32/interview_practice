#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef struct trie {
  trie *child[26];
  bool isEndOfWord;
  trie() {
    isEndOfWord = false;
    for (int i = 0; i < 26; i++) 
      child[i] = nullptr;
  }
} trie;

void addToTrie(trie *head, string x) {
  for (int i = 0; i < x.length(); i++) {
    if (!head->child[(int) x[i] - 'a']) {
      trie *ptr = new trie();
      head->child[(int) x[i] - 'a'] = ptr;
    }
    head = head->child[(int) x[i] - 'a'];
  }
  head->isEndOfWord = true;
}

bool search(trie *root, string key) {
  trie *crawl = root;

  for (int i = 0; i < key.length(); i++) {
    int index = key[i] - 'a';
    if (!crawl->child[index]) return false;
    crawl = crawl->child[index];
  }
  return ((crawl != nullptr) && (crawl->isEndOfWord == true));
}

int main() {
  trie head;
  addToTrie(&head, "the");
  cout << search(&head, "the") << endl;
  return 0;
}
