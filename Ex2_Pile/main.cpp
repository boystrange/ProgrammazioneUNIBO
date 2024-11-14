#include <iostream>

const int MAX = 1024;

// insert an element at the top of the stack
void push(int A[], int& size, const int e) {
    // precondition: 0 <= size && size < MAX
    if (size == MAX - 1) std::cerr << "push on full stack" << std::endl;
    else A[size++] = e;
}

// remove the element at the top of the stack
int pop(int A[], int& size) {
    // precondition: 0 <= size && size < MAX
    if (size == 0) {
        std::cerr << "pop on empty stack" << std::endl;
        return -1;
    } else return A[--size];
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
        push(A, size, i);
    print_stack(A, size);
    for (int i = 0; i < 5; i++)
        pop(A, size);
    print_stack(A, size);
}
