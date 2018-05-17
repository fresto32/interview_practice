#include <iostream>
#include <vector>

using namespace std;

typedef struct node {
  node* right;
  node* left;
  int val;
  node() {
    right = nullptr;
    left = nullptr;
  }
} node;

void makeUnitHelper(node *root, node *unit, int &order) {
  if (root) {
    if (root->left && !unit->left) {
      node *unit_l = new node();
      unit->left = unit_l;
    }
    makeUnitHelper(root->left, unit->left, order);
    unit->val = order++;
    if (root->right && !unit->right) {
      node *unit_r = new node();
      unit->right = unit_r;
    }
    makeUnitHelper(root->right, unit->right, order);
  }
}

node* makeUnit(node *root) {
  node* unit = new node();
  int order = 0;
  makeUnitHelper(root, unit, order);
  return unit;
}

void inorder(node *root) {
  if (root) {
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
  }
}

void remake(node *unit, vector<int> &k, node *r) {
  if (unit) {
    if (unit->left && !r->left) {
      node *u_l = new node();
      r->left = u_l;
    }
    remake(unit->left, k, r->left);
    r->val = k[unit->val];
    if (unit->right && !r->right) {
      node* u_r = new node();
      r->right = u_r;
    }
    remake(unit->right, k, r->right);
  }
}

int main() {
  node* ptr = new node();
  ptr->val = 1;
  node *l = new node();
  l->val = 2;
  node *r = new node(); 
  r->val = 3;
  ptr->right = r;
  ptr->left = l;

  


  node* unit = makeUnit(ptr);
  inorder(ptr);
  cout << endl;
  inorder(unit);
  vector<int> k;
  k.push_back(2);
  k.push_back(1);
  k.push_back(3);
  node *ptr2 = new node();
  remake(unit, k, ptr2);
  cout << endl;
  inorder(ptr2);
  return 0;
}
