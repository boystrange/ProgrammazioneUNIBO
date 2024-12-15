
#include <iostream>

struct Node {
  int elem;
  Node* left;
  Node* right;
};

// ESERCIZIO 2.1

int leaves(const Node* p) {
  if (p == nullptr) return 0;
  else if (p->left == nullptr && p->right == nullptr) return 1;
  else return leaves(p->left) + leaves(p->right);
}

// ESERCIZIO 2.2

bool upper(int elem, const Node* p) {
  return
    p == nullptr ||
    (p->elem <= elem && upper(elem, p->left) && upper(elem, p->right));
}

bool lower(int elem, const Node* p) {
  return
    p == nullptr ||
    (elem < p->elem && lower(elem, p->left) && lower(elem, p->right));
}

bool sorted(const Node* p) {
  return
    p == nullptr ||
    (upper(p->elem, p->left) && lower(p->elem, p->right) && sorted(p->left) && sorted(p->right));
}
