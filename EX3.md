# Pile, code e insiemi realizzati con liste dinamiche

## Esercizio 1

Implementare una pila per mezzo di una lista dinamica usando le
seguenti strutture

``` c++
struct Node {
	int   elem;
	Node* next;
};

struct Stack {
	Node* top;
};
```

e realizzando le seguenti funzioni:

* `void init(Stack& s)` per inizializzare una pila;
* `void push(Stack& s, int elem)` per inserire `elem` in cima alla
  pila;
* `void pop(Stack& s)` per rimuovere l'elemento in cima alla
  pila. La funzione deve stampare un messaggio di errore se la pila
  è vuota;
* `int top(const Stack& s)` per ottenere l'elemento in cima alla
  pila senza rimuoverlo. La funzione deve stampare un messaggio di
  errore e restituire `-1` se la pila è vuota.

## Esercizio 2

Implementare una coda per mezzo di una lista dinamica i cui nodi
sono rappresentati come nell'esercizio precedente. Fare uso della
struttura

``` c++
struct Queue {
	Node* head; // putatore al primo nodo della coda
	Node* tail; // puntatore all'ultimo nodo della coda
};
```

e realizzare le seguenti funzioni:

* `void init(Queue& q)` per inizializzare una coda;
* `bool empty(Queue& q)` per stabilire se la coda è vuota oppure no,
  restituendo `true` o `false` a seconda dei casi;
* `void enqueue(Queue& q, int elem)` per inserire `elem` in fondo
  alla coda;
* `void dequeue(Queue& q)` per rimuovere l'elemento in testa alla
  coda. La funzione deve stampare un messaggio di errore se la coda
  è vuota;
* `int head(const Queue& q)` per ottenere l'elemento in testa alla
  coda senza rimuoverlo. La funzione deve stampare un messaggio di
  errore e restituire `-1` se la coda è vuota;
* `int tail(const Queue& q)` per ottenere l'elemento in fondo alla
  coda senza rimuoverlo, gestendo il caso della coda vuota come per
  `head`.

## Esercizio 3

Implementare il tipo di dato **insieme** per mezzo di una lista
ordinata che non contiene elementi duplicati. Fare uso della
struttura

``` c++
struct Set {
	Node* data; // puntatore alla testa della lista ordinata
};
```

e realizzare le seguenti funzioni:

* `void init(Set& s)` per inizializzare un insieme in modo che sia
  vuoto;
* `bool empty(const Set& s)` per stabilire se l'insieme è vuoto
  oppure no, restituendo `true` o `false` a seconda dei casi;
* **IMPEGNATIVO** `void insert(Set& s, int elem)` per aggiungere
  `elem` all'insieme. La funzione non deve fare niente se `elem` è
  già presente nell'insieme;
* **IMPEGNATIVO** `void remove(Set& s, int elem)` per rimuovere
  `elem` dall'insieme. La funzione non deve fare niente se `elem`
  **non** è presente nell'insieme;
* `bool member(const Set& s, int elem)` per stabilire se `elem` è
  contenuto nell'insieme;
* `Set set_union(const Set& s, const Set& t)` per calcolare l'unione
  di `s` e `t`;
* `Set set_intersection(const Set& s, const Set& t)` per calcolare
  l'intersezione di `s` e `t`;
* `Set set_difference(const Set& s, const Set& t)` per calcolare la
  differenza di `s` e `t`;
* `void print_set(const Set& s)` per stampare tutti gli elementi
  dell'insieme.
