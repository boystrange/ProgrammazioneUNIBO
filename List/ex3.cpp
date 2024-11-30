#include <iostream>

struct Node {
  int   elem;
  Node* next;
};

struct Set {
  Node* min;
};

void init(Set& s) {
  s.min = NULL;
}

void insert(Set& s, int elem) {
  Node* p = s.min;
  Node* prev = NULL;
  while (p != NULL && p->elem < elem) {
    prev = p;
    p = p->next;
  }
  if (p == NULL || p->elem != elem) {
    Node* q = new Node;
    q->elem = elem;
    q->next = p;
    if (prev != NULL) prev->next = q;
    else s.min = q;
  }
}

void remove(Set& s, int elem) {
  Node* p = s.min;
  Node* prev = NULL;
  while (p != NULL && p->elem < elem) {
    prev = p;
    p = p->next;
  }
  if (p != NULL && p->elem == elem) {
    Node* q = p->next;
    delete p;
    if (prev != NULL) prev->next = q;
    else s.min = q;
  }
}

bool in(const Set& s, int elem) {
  Node* p = s.min;
  while (p != NULL && p->elem < elem)
    p = p->next;
  return p != NULL && p->elem == elem;
}

Set set_union(const Set& s, const Set& t) {
  Set r;
  init(r);
  for (Node* p = s.min; p != NULL; p = p->next)
    insert(r, p->elem);
  for (Node* p = t.min; p != NULL; p = p->next)
    insert(r, p->elem);
  return r;
}

Set set_intersection(const Set& s, const Set& t) {
  Set r;
  init(r);
  for (Node* p = s.min; p != NULL; p = p->next)
    if (in(t, p->elem)) insert(r, p->elem);
  return r;
}

