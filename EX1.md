# Esercizi su array riempiti parzialmente

## Esercizio 1

Una **pila** è un contenitore di elementi tale per cui il primo elemento
inserito è anche l'ultimo che viene rimosso. Le operazioni caratteristiche
supportate da una pila sono **top** (lettura dell'elemento in cima alla pila),
**push** (inserimento di un elemento in cima alla pila) e **pop** (rimozione
dell'elemento in cima alla pila). Implementare una pila che sia in grado di
contenere elementi di tipo `int` realizzando le seguenti funzioni:

* `push(A, size, elem)` inserisce `elem` nella pila `A` che già contiene `size`
  elementi e restituisce il nuovo numero di elementi della pila. Si suppone che
  l'array `A` abbia dimensione massima `MAX`, dove `MAX` è una costante definita
  globalmente. La funzione emette un messaggio di errore e restituisce -1 se la
  pila è piena.
* `pop(A, size)` rimuove l'elemento in cima alla pila `A` che già contiene
  `size` elementi e restituisce il nuovo numero di elementi della pila. La
  funzione emette un messaggio di errore e restituisce -1 se la pila è vuota.
* `top(A, size)` restituisce l'elemento in cima alla pila `A` che contiene
  `size` elementi. La funzione emette un messaggio di errore e restituisce -1 se
  la pila è vuota.
* `print_stack(A, size)` stampa gli elementi della pila dall'ultimo a quello in
  cima.

Scrivere un semplice `main` per verificare il comportamento delle funzioni
definite.

## Esercizio 2

Modificare l'implementazione della pila in modo tale che la dimensione corrente
della pila sia un argomento passato per **riferimento** per quelle operazioni
che possono alterarla. Cambiare di conseguenza il tipo delle funzioni affette da
questa modifica.

## Esercizio 3

Modificare l'implementazione della pila usando la seguente struttura per
accorpare l'array che contiene gli elementi e la dimensione corrente della pila:

```c++
struct Stack {
    int data[MAX];
    int size;      // numero di elementi nella pila
}
```

Aggiungere anche una funzione `init(stack)` che inizializza `stack` in modo che
sia una pila vuota, dove `stack` è una struttura di tipo `Stack`.

\clearpage

## Esercizio 4

È possibile realizzare una calcolatrice in [notazione polacca
inversa](https://it.wikipedia.org/wiki/Notazione_polacca_inversa) (RPN, da
Reverse Polish Notation) usando una pila. La calcolatrice legge da tastiera un
carattere alla volta:

* se il carattere è una cifra decimale (da `0` a `9`), allora la calcolatrice
  inserisce sulla pila il numero (da 0 a 9) corrispondente;
* se il carattere è `+`, allora la calcolatrice rimuove due elementi dalla pila
  e inserisce la loro somma sulla pila;
* se il carattere è `-`, allora la calcolatrice rimuove due elementi dalla pila
  e inserisce la loro differenza sulla pila;
* ecc.

Seguendo queste indicazioni implementare una calcolatrice RPN che supporti,
oltre alle suddette operazioni, anche moltiplicazione `*` e divisione `/`.

## Esercizio 5

Una **coda** è un contenitore di elementi tale per cui il primo elemento
inserito è anche il primo che viene rimosso. Le operazioni caratteristiche
supportate da una coda sono **front** e **back** (lettura del primo e
dell'ultimo elemento della coda), **enqueue** (inserimento di un elemento in
coda) e **dequeue** (rimozione dell'elemento in testa). Implementare una coda
che sia in grado di contenere elementi di tipo `int` utilizzando la seguente
struttura

```c++
struct Queue {
    int data[MAX];
    int head;      // indice del primo elemento della coda
    int size;      // numero di elementi nella coda
}
```

e realizzando le seguenti funzioni:

* `init(q)` inizializza la coda `q` in modo che sia una coda vuota.
* `empty(q)` restituisce `true` se la coda è vuota, `false` altrimenti.
* `full(q)` restituisce `true` se la coda è piena, `false` altrimenti.
* `front(q)` restituisce il primo elemento della coda (senza rimuoverlo). La
  funzione stampa un messaggio di errore se la coda è vuota.
* `back(q)` restituisce l'ultimo elemento della coda. La funzione stampa un
  messaggio di errore se la coda è vuota.
* `enqueue(q, elem)` inserisce `elem` in ultima posizione nella coda. La
  funzione stampa un messaggio di errore se la coda è piena.
* `dequeue(q)` rimuove il primo elemento della coda. La funzione stampa un
  messaggio di errore se la coda è vuota.
* `print_queue(q)` stampa gli elementi della coda dal primo all'ultimo.
