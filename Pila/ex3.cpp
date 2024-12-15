// ESERCIZIO 3
// struttura che incorpora array e dimensione della pila

#include <iostream>

const int MAX = 1024;

struct Stack {
  int data[MAX];
  int size;      // 0 <= size <= MAX
};

// inizializza una nuova pila
void init(Stack& stack) {
  stack.size = 0;
}

bool push(Stack& stack, const int elem) {
  if (stack.size == MAX) {
    std::cerr << "push on full stack" << std::endl;
    return false;
  } else {
    stack.data[stack.size++] = elem;
    return true;
  }
}

bool pop(Stack& stack) {
  if (stack.size == 0) {
    std::cerr << "pop on empty stack" << std::endl;
    return false;
  } else {
    stack.size--;
    return true;
  }
}

int top(const Stack& stack) {
  if (stack.size == 0) std::cerr << "top on empty stack" << std::endl;
  // attenzione: se la pila è vuota usa un indice illegale
  return stack.data[stack.size - 1];
}

void print_stack(const Stack& stack) {
  std::cout << "[";
  for (int i = 0; i < stack.size; i++)
    std::cout << " " << stack.data[i];
  std::cout << " ]" << std::endl;
}

int main() {
  Stack A;

  init(A);
  print_stack(A);
  for (int i = 0; i < 10; i++)
    push(A, i);
  print_stack(A);
  for (int i = 0; i < 5; i++)
    pop(A);
  print_stack(A);
}
