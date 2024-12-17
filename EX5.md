# Caso di studio: "grandi" numeri naturali

In questo caso di studio vediamo come usare la programmazione a oggetti per
arricchire il linguaggio C++ con "grandi numeri", ovvero numeri naturali il cui
numero di cifre è arbitrariamente grande (per quanto sempre finito). L'idea alla
base del caso di studio è molto semplice, basta ricordare il significato della
**notazione posizionale** che usiamo tutti i giorni per leggere e scrivere
numeri naturali. In base a tale notazione, la sequenza di $n$ cifre

$$c_{n-1}\cdots c_2c_1c_0$$

denota il numero

$$
	c_{n-1} \cdot 10^{n-1} + \cdots + c_2 \cdot 10^2 + c_1 \cdot 10^1 + c_0 \cdot 10^0
$$

Usando la notazione posizionale possiamo rappresentare numeri naturali
arbitrariamente grandi per mezzo di **sequenze di cifre** arbitrariamente
lunghe. Quando usiamo la notazione posizionale in **base 10** ogni cifra è un
valore compreso tra 0 e 9. In generale la base può essere un numero arbitrario
maggiore di 2: più è grande la base, più grandi sono i numeri che riusciamo a
rappresentare fissato un certo numero di cifre.

Iniziamo con l'importare alcuni moduli della libreria standard. A parte il noto
modulo `iostream`, importiamo anche `iomanip` che si rivelerà utile in seguito.

## Definizioni di base

``` c++
#include <iostream>
#include <iomanip>
```

Inoltre, definiamo alcune costanti relative alle nostre sequenze di cifre:

``` c++
const int BASE   = 1000000000;  // base del sistema di numerazione posizionale
const int DIGITS = log10(BASE); // numero di cifre decimali necessarie per rappresentare una base
const int SIZE   = 1000;        // numero massimo di cifre
```

L'obiettivo è realizzare una classe `Nat` con la struttura seguente:

``` c++
class Nat {
private:
  int digit[SIZE]; // sequenza di cifre del numero

public:
  Nat(int n = 0);
  Nat add(const Nat& n) const;
  Nat mul(int n) const;
  void print() const;
};
```

in cui:

* il campo `digit` è un array di `SIZE` cifre in base `BASE`;
* il costruttore `Nat(n)` consente di creare il numero `n`;
* il metodo `add(n)` calcola la somma del numero su cui viene invocato ed `n`.
  Da notare che il metodo è qualificato come `const`, ovvero tale metodo **non
  modifica** il numero su cui viene invocato. Invece, restituisce un **nuovo
  numero** che rappresenta il risultato;
* il metodo `mul(n)` calcola la moltiplicazione del numero su cui viene invocato
  per `n`. Come nel caso di `add`, anche `mul` crea un nuovo numero con il
  risultato invece di modificare l'oggetto su cui viene invocato;
* il metodo `print()` stampa sullo schermo il numero su cui viene invocato.

## Costruttore

``` c++
Nat::Nat(int n) {
  for (int i = 0; i < SIZE; i++) {
    digit[i] = n % BASE;
    n /= BASE;
  }
}
```

Il costruttore inizializza le cifre del numero naturale effettuando una serie di
divisioni successive di `n` per la base. Ogni divisione determina un resto che
diventa una cifra del numero naturale. Da notare che l'array di cifre viene
inizializzato a partire dall'indice 0. In altre parole, stiamo decidendo che il
primo elemento dell'array è la cifra **meno significativa**.

A titolo di esempio, prendendo la definizione di `BASE` data sopra, il numero
1876 verrebbe rappresentato con un array in cui il primo elemento è 6, il
secondo elemento è 7, il terzo elemento è 8, il quarto elemento è 1 e tutti gli
elementi successivi sono 0.

## Addizione

``` c++
Nat Nat::add(const Nat& n) const {
  Nat r;
  int carry = 0;
  for (int i = 0; i < SIZE; i++) {
    int s = digit[i] + n.digit[i] + carry;
    r.digit[i] = s % BASE;
    carry = s / BASE;
  }
  return r;
}
```

Realizziamo l'addizione di due numeri naturali usando l'algoritmo che si studia
alla scuola primaria. Definiamo una variabile locale `r` che conterrà il
risultato della somma e una variabile locale `carry` che rappresenta il
**riporto** ottenuto dalle somme delle cifre corrispondenti dei due numeri
naturali da sommare.

## Moltiplicazione

``` c++
Nat Nat::mul(int n) const {
  if (n == 0) return Nat(0);
  else return this->add(this->mul(n - 1));
}
```

Senza avere pretese di efficienza, possiamo realizzare la moltiplicazione per
mezzo di un semplice **metodo ricorsivo**, tenuto conto che la moltiplicazione
$m \times n$ può essere espressa in tal modo:

$$
	m \times n =
	\left\{
		\begin{array}{ll}
			0 & \text{se $n = 0$} \\
			m + m \times (n - 1) & \text{se $n > 0$}
		\end{array}
	\right.
$$

## Stampa di un numero naturale

``` c++
void Nat::print() const {
  for (int i = 1; i <= SIZE; i++)
    std::cout << std::setw(DIGITS) << std::setfill('0') << digit[SIZE - i];
}
```

Per stampare un numero naturale basta stamparne tutte le cifre che lo
compongono. Il manipolatore `setw` indica che desideriamo stampare le cifre
facendo uso di `DIGITS` cifre decimali, mentre il manipolatore `setfill` indica
che vogliamo riempire eventuali spazi vuoti con il carattere `0`.

Notare che la correttezza di questo metodo dipende dal fatto che `BASE` sia un
multiplo di 10.

## Esercizi

1. Realizzare una funzione `Nat fact(int n)` che calcola il fattoriale di `n`
   usando grandi numeri.
2. Realizzare una funzione `Nat fibo(int n)` che calcoli il numero di Fibonacci
   con indice `n`, ricordando che la sequenza di Fibonacci è composta dai numeri
   $0,1,1,2,3,5,8,\dots$
3. Modificare `print` in modo tale che il metodo non stampi le cifre `0` non
   necessarie.
4. Aggiungere un metodo `bool zero()` per determinare se il numero naturale su
   cui viene invocato è zero oppure no.
5. Aggiungere un metodo `Nat pred()` per calcolare il predecessore di un numero
   naturale. Se il numero è 0, il risultato sarà il numero naturale più grande
   rappresentabile con `SIZE` cifre in base `BASE`.
6. Usando `pred` e `zero` definire una funzione iterativa `Nat mul(const Nat& x,
   Nat y)` per moltiplicare due numeri naturali. Esprimere la moltiplicazione in
   termini di somme successive.
7. Usando la funzione `mul` dell'esercizio precedente, definire una funzione
   ricorsiva `Nat pow(const Nat& x, int n)` per calcolare $x^n$.
8. Definire una funzione `Nat sub(Nat x, Nat y)` per sottrarre `y` da `x`.