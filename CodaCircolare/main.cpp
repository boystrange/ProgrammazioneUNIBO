#include <iostream>

const int MAX = 16;

struct Queue {
    int data[MAX];
    int head;
    int size;
};

void init(Queue& q) {
    q.head = 0;
    q.size = 0;
}

bool empty(const Queue& q) {
    return q.size == 0;
}

bool full(const Queue& q) {
    return q.size == MAX;
}

int head(const Queue& q) {
    if (empty(q)) {
        std::cerr << "queue is empty" << std::endl;
        return -1;
    }
    return q.data[q.head];
}

void enqueue(Queue& q, int elem) {
    if (full(q)) std::cerr << "queue is full" << std::endl;
    else {
        q.data[(q.head + q.size) % MAX] = elem;
        q.size++;
    }
}

void dequeue(Queue& q) {
    if (!empty(q)) {
        q.head = (q.head + 1) % MAX;
        q.size--;
    }
}

void print_queue(const Queue& q) {
    std::cout << "[";
    for (int i = 0; i < q.size; i++)
        std::cout << " " << q.data[(q.head + i) % MAX];
    std::cout << " ]" << std::endl;
}

int main() {
    Queue q{};

    init(q);
    print_queue(q);
    for (int i = 0; i < 10; i++) enqueue(q, i);
    print_queue(q);
    for (int i = 0; i < 5; i++) dequeue(q);
    print_queue(q);
    for (int i = 0; i < 10; i++) enqueue(q, i);
    print_queue(q);
}
