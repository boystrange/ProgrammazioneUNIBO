// ESERCIZIO 2
// passaggio per riferimento della dimensione della pila

#include <iostream>

const int MAX = 1024;

// restituisce true se l'inserimento ha successo, false altrimenti
bool push(int A[], int& size, const int e) {
  if (size == MAX) {
    std::cerr << "push on full stack" << std::endl;
    return false;
  } else {
    A[size++] = e;
    return true;
  }
}

// restituisce true se la rimozione ha successo, false alstrimenti
bool pop(int A[], int& size) {
  if (size == 0) {
    std::cerr << "pop on empty stack" << std::endl;
    return false;
  } else {
    size--;
    return true;
  }
}

int top(int A[], const int size) {
  if (size == 0) std::cerr << "top on empty stack" << std::endl;
  // attenzione: se la pila è vuota usa un indice illegale
  return A[size - 1];
}

void print_stack(int A[], const int size) {
  std::cout << "[";
  for (int i = 0; i < size; i++)
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
