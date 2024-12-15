
#include <iostream>

struct Node {
  int elem;
  Node* next;
};

// ESERCIZIO 1.1
int min_list(const Node* p) {
  if (p == nullptr) {
    std::cerr << "min of empty list" << std::endl;
    return -1;
  } else
    return p->next == nullptr ? p->elem : std::min(p->elem, min_list(p->next));
}

// ESERCIZIO 1.2
int max_list(const Node* p) {
  if (p == nullptr) {
    std::cerr << "max of empty list" << std::endl;
    return -1;
  } else
    return p->next == nullptr ? p->elem : std::max(p->elem, max_list(p->next));
}

// ESERCIZIO 1.3
bool sorted(const Node* p) {
  return
    p == nullptr ||
    p->next == nullptr ||
    p->elem <= p->next->elem && sorted(p->next);
}

Node* node(int elem, Node* next) {
  Node* p = new Node;
  p->elem = elem;
  p->next = next;
  return p;
}

int main() {
  Node* p = node(3, node(7, node(-2, node(5, nullptr))));
  std::cout << "min = " << min_list(p) << std::endl;
  std::cout << "max = " << max_list(p) << std::endl;
  std::cout << "sorted = " << sorted(p) << std::endl;
}
