// ESERCIZIO 4: CALCOLATRICE IN NOTAZIONE POLACCA INVERSA

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

// per comodità faccio in modo che pop restiuisca l'elemento rimosso
int pop(Stack& stack) {
  if (stack.size == 0) std::cerr << "pop on empty stack" << std::endl;
  // attenzione: se la pila è vuota usa un indice illegale
  return stack.data[--stack.size];
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

// eval restituisce true se l'esecuzione della calcolatrice deve
// continuare, false se deve terminare
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
  Stack A;
  char c;

  init(A);
  do {
    print_stack(A);
    std::cout << "> ";
    std::cin >> c;
  } while (eval(A, c));
}
