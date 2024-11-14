#include <iostream>

const int MAX = 1024;

// insert an element at the top of the stack
int push(int A[], const int size, const int e) {
    // precondition: 0 <= size && size < MAX
    if (size == MAX - 1) {
        std::cerr << "push on full stack" << std::endl;
        return -1;
    } else {
        A[size] = e;
        return size + 1;
    }
}

// remove the element at the top of the stack
int pop(int A[], const int size) {
    // precondition: 0 <= size && size < MAX
    if (size == 0) std::cerr << "pop on empty stack" << std::endl;
    return size - 1;
}

int top(int A[], const int size) {
    // precondition: 0 < size && size <= MAX
    if (size == 0) std::cerr << "top on empty stack" << std::endl;
    return A[size - 1];
}

// print the content of the stack, top first
void print_stack(int A[], const int size) {
    std::cout << "[";
    for (int i = 0; i < stack.size; i++)
        std::cout << " " << A[i];
    std::cout << " ]" << std::endl;
}

int main() {
    int A[MAX];
    int size = 0;

    print_stack(A, size);
    for (int i = 0; i < 10; i++)
        size = push(A, size, i);
    print_stack(A, size);
    for (int i = 0; i < 5; i++)
        size = pop(A, size);
    print_stack(A, size);
}
