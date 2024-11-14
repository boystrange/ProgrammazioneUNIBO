#include <iostream>

const int MAX = 1024;

// insert an element at the top of the stack
int push(int A[], const int k, const int e) {
    // precondition: 0 <= k && k < MAX
    if (k == MAX - 1) return -1;
    else {
        A[k] = e;
        return k + 1;
    }
}

// remove the element at the top of the stack
int pop(int A[], const int k) {
    // precondition: 0 <= k && k < MAX
    return (k == 0) ? -1 : k - 1;
}

int top(int A[], const int k) {
    // precondition: 0 < k && k <= MAX
    return A[k - 1];
}

// print the content of the stack, top first
void print_stack(int A[], const int k) {
    std::cout << "[";
    for (int i = k - 1; i >= 0; i--)
        std::cout << " " << A[i];
    std::cout << " ]" << std::endl;
}

int main() {
    int A[MAX];
    int k = 0;

    print_stack(A, k);
    for (int i = 0; i < 10; i++)
        k = push(A, k, i);
    print_stack(A, k);
    for (int i = 0; i < 5; i++)
        k = pop(A, k);
    print_stack(A, k);
}
