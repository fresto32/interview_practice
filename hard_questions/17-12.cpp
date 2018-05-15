#include <iostream>
#include <vector>

using namespace std;

typedef struct Binode {
  Binode* left;
  Binode* right;
  int val;

  Binode(int value) {
    left = nullptr;
    right = nullptr;
    val = value;
  }

} Binode;

void BtToDLL(Binode *root, Binode **head_ref) {
  if (root == nullptr) return;
  BtToDLL(root->right, head_ref);

  root->right = *head_ref;

  if (!(*head_ref)) (*head_ref)->left = root;
  *head_ref = root;

  BtToDLL(root->left, head_ref);
}

Binode* Binoder(int value) {
  return new Binode(value);
}

int main() {
  bool k = nullptr == nullptr;
  cout << "np == np : " << k << endl;
  Binode *root = new Binode(5);
  root->left = Binoder(3);
  root->right = Binoder(6);
  root->left->left = Binoder(1);
  root->left->right = Binoder(4);
  root->right->right = Binoder(8);
  root->left->left->left = Binoder(0);
  root->left->left->right = Binoder(2);
  root->right->right->left = Binoder(7);
  root->right->right->right = Binoder(9);
  cout << "b4";
  Binode *head = nullptr;
  BtToDLL(root, &head);
  cout << "here";
  while (head) {
    cout << head->val << " ";
    head = head->right;
  }
  return 0;
}
