#include <iostream>

struct Node {
  int   elem;
  Node* next;
};

struct Stack {
  Node* top;
};

void init(Stack& s) {
  s.top = NULL;
}

void push(Stack& s, int elem) {
  Node* p = new Node;
  p->elem = elem;
  p->next = s.top;
  s.top = p;
}

void pop(Stack& s) {
  if (s.top != NULL) {
    Node* p = s.top;
    s.top = p->next;
    delete p;
  } else {
    std::cerr << "pop on empty stack" << std::endl;
  }
}

int top(Stack& s) {
  if (s.top != NULL)
    return s.top->elem;
  else {
    std::cerr << "top on empty stack" << std::endl;
    return -1;
  }
}
