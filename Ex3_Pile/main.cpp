#include <iostream>

const int MAX = 1024;

struct Stack {
    int data[MAX];
    int size; // 0 <= size < MAX
};

// initialize a new stack
void init(Stack& stack) {
    stack.size = 0;
}

// insert an element at the top of the stack
void push(Stack& stack, const int elem) {
    if (stack.size == MAX - 1) std::cerr << "push on full stack" << std::endl;
    else stack.data[stack.size++] = elem;
}

// remove the element at the top of the stack
int pop(Stack& stack) {
    if (stack.size == 0) {
        std::cerr << "pop on empty stack" << std::endl;
        return -1;
    } else return stack.data[--stack.size];
}

int top(const Stack& stack) {
    if (stack.size == 0) std::cerr << "top on empty stack" << std::endl;
    return stack.data[stack.size - 1];
}

// print the content of the stack, top first
void print_stack(const Stack& stack) {
    std::cout << "[";
    for (int i = 0; i < stack.size; i++)
        std::cout << " " << stack.data[i];
    std::cout << " ]" << std::endl;
}

int main() {
    Stack A{};

    init(A);
    print_stack(A);
    for (int i = 0; i < 10; i++)
        push(A, i);
    print_stack(A);
    for (int i = 0; i < 5; i++)
        pop(A);
    print_stack(A);
}
