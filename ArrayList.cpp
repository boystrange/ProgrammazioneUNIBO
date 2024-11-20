#include <iostream>

const int MAX = 10;

typedef int Ptr;

struct Node {
  int elem; // elemento del nodo
  Ptr next; // indice del prossimo nodo, -1 se questo è l'ultimo nodo
};

struct List {
  Node node[MAX]; // tutti i nodi della lista
  Ptr head;       // indice della testa della lista
  Ptr free;       // indice della testa della lista libera
};

void init(List& l) {
  l.head = -1;
  l.free = 0;
  for (int i = 0; i < MAX; i++)
    l.node[i].next = i + 1;
  l.node[MAX - 1].next = -1;
}

Ptr alloc(List& l, int elem, Ptr next) {
  Ptr p = l.free;
  if (p == -1) {
    std::cerr << "out of memory" << std::endl;
    return -1;
  }
  l.free = l.node[p].next;
  l.node[p].elem = elem;
  l.node[p].next = next;
  return p;
}

void free(List& l, Ptr p) {
  if (p != -1) {
    l.node[p].next = l.free;
    l.free = p;
  }
}

void push_front(List& l, int elem) {
  Ptr p = alloc(l, elem, l.head);
  if (p != -1) l.head = p;
}

void pop_front(List& l) {
  if (l.head != -1) {
    Ptr p = l.head;
    l.head = l.node[l.head].next;
    free(l, p);
  }
}

void push_back(List& l, int elem) {
  Ptr p = l.head;
  while (p != -1 && l.node[p].next != -1)
    p = l.node[p].next;
  if (p == -1)
    // la lista è vuota, l'inserimento è in testa
    push_front(l, elem);
  else {
    // la lista non è vuota e p è l'indice dell'ultimo elemento
    Ptr q = alloc(l, elem, -1);
    if (q != -1) l.node[p].next = q;
  }
}

void pop_back(List& l) {
  Ptr prev = -1;
  Ptr p = l.head;
  // cerco l'ultimo nodo
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

void reverse(List& l) {
  Ptr prev = -1;
  Ptr p = l.head;
  while (p != -1) {
    const Ptr q = l.node[p].next;
    l.node[p].next = prev;
    prev = p;
    p = q;
  }
  l.head = prev;
}

void insert(List& l, int elem) {
  Ptr p = l.head;
  Ptr prev = -1;
  while (p != -1 && l.node[p].elem < elem) {
    prev = p;
    p = l.node[p].next;
  }
  Ptr q = alloc(l, elem, p);
  if (prev != -1) l.node[prev].next = q;
  else l.head = q;
}

void remove(List& l, Ptr q) {
  Ptr p = l.head;
  Ptr prev = -1;
  while (p != -1 && p != q) {
    prev = p;
    p = l.node[p].next;
  }
  if (p != -1) {
    if (prev != -1)
      l.node[prev].next = l.node[p].next;
    else
      l.head = l.node[p].next;
    free(l, p);
  }
}

int length(const List& l) {
  int n = 0;
  for (int p = l.head; p != -1; p = l.node[p].next)
    n++;
  return n;
}

void create_list(List& l) {
  for (int i = 0; i < 16; i++)
    insert(l, rand() % 50);
}

void print_list(const List& l) {
  std::cout << "[";
  for (Ptr p = l.head; p != -1; p = l.node[p].next)
    std::cout << " " << l.node[p].elem;
  std::cout << " ]" << std::endl;
}

int main() {
  List l;
  init(l);
  create_list(l);
  print_list(l);
  reverse(l);
  print_list(l);
  pop_back(l);
  print_list(l);
}
