// Given a sorted (increasing order) array with unique elements, write an 
// algorithm to create a BST with minimal height

#include <iostream>
using namespace std;
typedef struct node {
  node *left;
  node *right;
  int val;

  node(int value) {
    val = value;
    left = nullptr;
    right = nullptr;
  }

} node;
node *ptr1 = new node(6);

void preOrderTraversal(node* head) {
  if (head) {
    cout << head->val << endl;
    preOrderTraversal(head->left);
    preOrderTraversal(head->right);
  }
}

void addToBST(node *head, int value) {
  node* next = head;
  node* parent = head;
  while (next) {
    parent = next;
    next = (value < head->val) ? parent->left : parent->right;
  }
  cout << endl;

  node *ptr = new node(value);
  if (value < parent->val) {
    parent->left = ptr;
  } else {
    parent->right = ptr;
  }
}

void arrToBST(node* head, int arr[], int start, int end) {
  int mid = (start+end)/2;
  addToBST(head, arr[mid]);
  preOrderTraversal(ptr1);
  if (start <= mid-1) arrToBST(head, arr, start, mid-1);
  if (end >= mid+1) arrToBST(head, arr, mid+1, end);
}
  
void inOrderTraversal(node* head) {
  if (head) {
    preOrderTraversal(head->left);
    cout << head->val << endl;
    preOrderTraversal(head->right);
  }
}

int main() {
  int arr[11] = {1,2,3,4,5,6,7,8,9,10,11};
  arrToBST(ptr1, arr, 0, 4);
  arrToBST(ptr1, arr, 6, 10);

  cout << endl << endl;
  preOrderTraversal(ptr1);

  return 0;
}
