#include <iostream>

using namespace std;

//Deck shuffle(Deck deck) {
//  Deck shuffled;
//  for (int i = 0; i < 52; i++) {
//    shuffled.emplace(deck.remove(random(i) % (52 - i))); //deck is a doubly 
//                                                         //linked list
//  }
//  return shuffled;
//}

template <size_t els>
void shuffleArrayIteratively(int (*cards)[els]) {
  for (int i = 0; i < els; i++) {
    int k = rand() % (i+1);
    int temp = (*cards)[k];
    (*cards)[k] = (*cards)[i];
    (*cards)[i] = temp;
  }
}

int main() {
  int cards[52];
  for (int i = 0; i < 52; i++) cards[i] = i;
  shuffleArrayIteratively(&cards);
  for (int i = 0; i < 52; i++) cout << cards[i] << " ";
  return 0;
}
