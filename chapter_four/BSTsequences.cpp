#include <vector>
#include <deque>
#include <utility>
#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

typedef struct node {
  node* left;
  node* right;
  int val;
}node;

void perm(vector<int> *n, deque<pair<int, int> > *to_p, int k = 0) {
  int start = get<0>(to_p->at(k));
  int end = get<1>(to_p->at(k));
  do {
    if (k != to_p->size() - 1) {
      perm(n, to_p, k+1);
    }
    if (k == to_p->size() - 1) {
       for (int j = 0; j < n->size(); j++) {
         cout << n->at(j) << " ";
       }
       cout << endl;
    }
  } while(next_permutation(n->begin() + start, n->begin() + end));
}

void BSTseq(node *n) {
  deque<pair<int, int> > to_perm;
  vector<int> nums;
  nums.push_back(n->val);
  queue<node*> q;
  int skipped = 0, level = 1, nodes = 1, start = 1;

  do {
    if (n->left) {
      nums.push_back(n->left->val);
      q.push(n->left);
      nodes++;
    } else skipped++;

    if (n->right) {
      nums.push_back(n->right->val);
      q.push(n->right);
      nodes++;
    } else skipped++;

    if (nodes + skipped == pow(2,level)) {
      to_perm.push_back(make_pair(start, nodes));
      level++;
      skipped *= 2;
      start = nodes;
    }
    n = q.front();
    q.pop();
  } while (!(n->left) || !(n->right));
  perm(&nums, &to_perm);
}

int main() {
  vector<int> nums;
  nums.push_back(2);
  nums.push_back(1);
  nums.push_back(3);

  deque<pair<int, int> > to_p;

  to_p.push_back(make_pair(1,3));

  perm(&nums, &to_p);
  
  return 0;
}

