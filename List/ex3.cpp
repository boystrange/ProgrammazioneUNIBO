#include <iostream>

struct Node {
  int   elem;
  Node* next;
};

struct Set {
  Node* head;
};

void init(Set& s) {
  s.head = NULL;
}

void insert(Set& s, int elem) {
  Node* p = s.head;
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
    else s.head = q;
  }
}

void remove(Set& s, int elem) {
  Node* p = s.head;
  Node* prev = NULL;
  while (p != NULL && p->elem < elem) {
    prev = p;
    p = p->next;
  }
  if (p != NULL && p->elem == elem) {
    Node* q = p->next;
    delete p;
    if (prev != NULL) prev->next = q;
    else s.head = q;
  }
}

bool member(const Set& s, int elem) {
  Node* p = s.head;
  while (p != NULL && p->elem < elem)
    p = p->next;
  return p != NULL && p->elem == elem;
}

Set set_union(const Set& s, const Set& t) {
  Set r;
  init(r);
  for (Node* p = s.head; p != NULL; p = p->next)
    insert(r, p->elem);
  for (Node* p = t.head; p != NULL; p = p->next)
    insert(r, p->elem);
  return r;
}

Set set_intersection(const Set& s, const Set& t) {
  Set r;
  init(r);
  for (Node* p = s.head; p != NULL; p = p->next)
    if (member(t, p->elem)) insert(r, p->elem);
  return r;
}

Set set_difference(const Set& s, const Set& t) {
  Set r;
  init(r);
  for (Node* p = s.head; p != NULL; p = p->next)
    if (!member(t, p->elem)) insert(r, p->elem);
  return r;
}

void print_set(const Set& s) {
  std::cout << "{";
  for (Node* p = s.head; p != NULL; p = p->next)
    std::cout << " " << p->elem;
  std::cout << " }" << std::endl;
}

