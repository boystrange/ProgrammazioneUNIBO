#include <iostream>

struct Node {
  int   elem;
  Node* next;
};

struct Queue {
  Node* head;
  Node* tail;
};

void init(Queue& q) {
  q.head = q.tail = NULL;
}

bool empty(const Queue& q) {
  return q.head == NULL;
}

void enqueue(Queue& q, int elem) {
  Node* p = new Node;
  p->elem = elem;
  p->next = NULL;
  if (q.tail != NULL) {
    q.tail->next = p;
    q.tail = p;
  } else
    q.head = q.tail = p;
}

void dequeue(Queue& q) {
  Node* p = q.head;
  if (p->next != NULL)
    q.head = p->next;
  else
    q.head = q.tail = NULL;
  delete p;
}

int head(const Queue& q) {
  if (q.head != NULL)
    return q.head->elem;
  else {
    std::cerr << "head on empty queue" << std::endl;
    return -1;
  }
}

int main() {
  Queue q;
  init(q);
  for (int i = 0; i < 10; i++) {
    int elem = rand() % 50;
    std::cout << " in " << elem << std::endl;
    enqueue(q, elem);
  }
  for (; !empty(q); dequeue(q))
    std::cout << "out " << head(q) << std::endl;
}
