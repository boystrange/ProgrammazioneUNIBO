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
    for (int i = stack.size - 1; i >= 0; i--)
        std::cout << " " << stack.data[i];
    std::cout << " ]" << std::endl;
}

bool eval(Stack& stack, char c) {
    if (c >= '0' && c <= '9')
        push(stack, c - '0');
    else if (c == '+') {
        const int x = pop(stack);
        const int y = pop(stack);
        push(stack, x + y);
    } else if (c == '-') {
        const int x = pop(stack);
        const int y = pop(stack);
        push(stack, y - x);
    } else if (c == '*') {
        const int x = pop(stack);
        const int y = pop(stack);
        push(stack, x * y);
    } else if (c == '.')
        return false;
    return true;
}

int main() {
    Stack A{};
    char c;

    init(A);
    do {
        print_stack(A);
        std::cout << "> ";
        std::cin >> c;
    } while (eval(A, c));
}
