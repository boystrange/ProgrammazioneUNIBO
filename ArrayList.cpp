#include <iostream>

const int MAX = 1024;

struct Node {
  int elem;
  int next;
};

struct List {
  Node node[MAX];
  int head;
  int free;
};

void init(List& l) {
  l.head = -1;
  l.free = 0;
  for (int i = 0; i < MAX; i++)
    l.node[i].next = i + 1;
  l.node[MAX - 1].next = -1;
}

int alloc(List& l, int elem, int next) {
  int p = l.free;
  if (p == -1) return -1;
  l.free = l.node[p].next;
  l.node[p].elem = elem;
  l.node[p].next = next;
  return p;
}

void free(List& l, int p) {
  if (p != -1) {
    l.node[p].next = l.free;
    l.free = p;
  }
}

bool push(List& l, int elem) {
  l.head = alloc(l, elem, l.head);
  return l.head != -1;
}

void insert(List& l, int elem) {
  int p = l.head;
  int prev = -1;
  while (p != -1 && l.node[p].elem < elem) {
    prev = p;
    p = l.node[p].next;
  }
  int q = alloc(l, elem, p);
  if (prev != -1) l.node[prev].next = q;
  else l.head = q;
}

void create_list(List& l) {
  for (int i = 0; i < 16; i++)
    insert(l, rand() % 50);
}

void print_list(const List& l) {
  std::cout << "[";
  for (int p = l.head; p != -1; p = l.node[p].next)
    std::cout << " " << l.node[p].elem;
  std::cout << " ]" << std::endl;
}

void reverse(List& l) {
  int prev = -1;
  int p = l.head;
  while (p != -1) {
    const int q = l.node[p].next;
    l.node[p].next = prev;
    prev = p;
    p = q;
  }
  l.head = prev;
}

void remove_last(List& l) {
  int prev = -1;
  int p = l.head;
  while (p != -1 && l.node[p].next != -1) {
    prev = p;
    p = l.node[p].next;
  }
  if (p != -1) { // c'era un nodo da rimuovere
    // l.node[p].next == -1
    if (prev != -1) l.node[prev].next = -1;
    else l.head = -1;
    free(l, p);
  }
}

int main() {
  List l;
  init(l);
  create_list(l);
  print_list(l);
  reverse(l);
  print_list(l);
  remove_last(l);
  print_list(l);
}
