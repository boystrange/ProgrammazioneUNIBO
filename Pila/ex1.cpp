// ESERCIZIO 1

#include <iostream>

const int MAX = 1024;

// inserisce elemento in cima alla pila
int push(int A[], const int size, const int e) {
    // precondizione: 0 <= size && size <= MAX
    if (size == MAX) {
        std::cerr << "push on full stack" << std::endl;
        return -1;
    } else {
        A[size] = e;
        return size + 1;
    }
}

// rimuove elemento dalla cima della pila
int pop(int A[], const int size) {
    // precondizione: 0 <= size && size <= MAX
    if (size == 0) std::cerr << "pop on empty stack" << std::endl;
    return size - 1;
}

// restituisce elemento in cima alla pila senza rimuoverlo
int top(int A[], const int size) {
    // precondizione: 0 <= size && size <= MAX
    if (size == 0) std::cerr << "top on empty stack" << std::endl;
    return A[size - 1];
}

// stampa il contenuto della pila, l'elemento in cima più a destra
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
        size = push(A, size, i);
    print_stack(A, size);
    for (int i = 0; i < 5; i++)
        size = pop(A, size);
    print_stack(A, size);
}
