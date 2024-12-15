
#include <iostream>

struct Node {
  int elem;
  Node* next;
  Node* child;
};

// ESERCIZIO 3.1
int depth(const Node* p) {
  if (p == nullptr) return 0;
  else return std::max(1 + depth(p->child), depth(p->next));
}

// ESERCIZIO 3.2
int sum(const Node* p) {
  return p == nullptr ? 0 : p->elem + sum(p->next) + sum(p->child);
}

// ESERCIZIO 3.3
void post(const Node* p) {
  if (p != nullptr) {
    post(p->child);
    std::cout << p->elem << " ";
    post(p->next);
  }
}

// ESERCIZIO 3.4
int order(const Node* p) {
  int w = 0;
  int cw = 0;
  while (p != nullptr) {
    cw = std::max(cw, order(p->child));
    w++;
    p = p->next;
  }
  return std::max(w, cw);
}

Node* node(int elem, Node* next, Node* child) {
  Node* p = new Node;
  p->elem = elem;
  p->next = next;
  p->child = child;
  return p;
}

int main() {
  Node* p =
    node(3,
	 nullptr,
	 node(7,
	      node(-2,
		   node(5,
			node(25,
			     nullptr,
			     node(17,
				  node(9,
				       node(15, nullptr, nullptr),
				       nullptr),
				  nullptr)),
			nullptr),
		   node(50, nullptr, nullptr)),
	      nullptr));
  std::cout << "depth = " << depth(p) << std::endl;
  std::cout << "sum   = " << sum(p) << std::endl;
  std::cout << "order = " << order(p) << std::endl;
  post(p);
  std::cout << std::endl;
}
