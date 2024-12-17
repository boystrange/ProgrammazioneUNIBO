# Caso di studio: quanto fa mille fattoriale?

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

## Definizioni di base

Importiamo due moduli della libreria standard. A parte il noto modulo
`iostream`, importiamo anche `iomanip` che si rivelerà utile in seguito.

``` c++
#include <iostream>
#include <iomanip>
```

Inoltre, definiamo alcune costanti relative alle nostre sequenze di cifre:

``` c++
const int BASE   = 1000000000;  // base del sistema di numerazione posizionale
const int DIGITS = log10(BASE); // numero di cifre decimali necessarie per BASE
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

* il campo `digit` è un array di `SIZE` cifre in base `BASE`, dunque ogni cifra
  ha un valore compreso tra `0` (incluso) e `BASE` (escluso);
* il costruttore `Nat(n)` consente di creare il numero `n >= 0`;
* il metodo `add(n)` calcola la somma del numero su cui viene invocato ed `n`.
  Da notare che il metodo è qualificato come `const`, ovvero tale metodo **non
  modifica** il numero su cui viene invocato. Invece, restituisce un **nuovo
  numero** che rappresenta il risultato;
* il metodo `mul(n)` calcola la moltiplicazione del numero su cui viene invocato
  per `n`, dove `0 <= n < BASE`. Come nel caso di `add`, anche `mul` crea un
  nuovo numero con il risultato invece di modificare l'oggetto su cui viene
  invocato;
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
diventa una cifra del numero naturale.

Da notare che l'array di cifre viene inizializzato a partire dall'indice 0. In
altre parole, stiamo decidendo che il primo elemento dell'array è la **cifra
meno significativa**. A titolo di esempio, se la costante `BASE` fosse 10, il
numero 1876 verrebbe rappresentato con un array in cui il primo elemento è 6, il
secondo elemento è 7, il terzo elemento è 8, il quarto elemento è 1 e tutti gli
elementi successivi sono 0.

## Addizione

``` c++
Nat Nat::add(const Nat& n) const {
  Nat r;
  int co = 0;
  for (int i = 0; i < SIZE; i++) {
    int s = digit[i] + n.digit[i] + co;
    r.digit[i] = s % BASE;
    co = s / BASE;
  }
  return r;
}
```

Realizziamo l'addizione di due numeri naturali usando l'algoritmo che si studia
alla scuola primaria. Usiamo una variabile locale `r` per contenere il risultato
della somma e una variabile locale `co` per contenere il **riporto**
(carry-over) generato dalle somme delle cifre corrispondenti dei due numeri
naturali da sommare.

## Moltiplicazione

``` c++
Nat Nat::mul(int n) const {
  if (n == 0) return Nat(0);
  else if (n % 2 == 0) {
    Nat r = mul(n / 2);
    return r.add(r);
  } else return add(mul(n - 1));
}
```

Realizziamo la moltiplicazione usando la seguente definizione ricorsiva di
prodotto:

$$
  m \times n =
  \left\{
    \begin{array}{ll}
      0 & \text{se $n = 0$} \\
      (m \times (n / 2)) + (m \times (n / 2)) & \text{se $n > 0$ è pari} \\
      m + m \times (n - 1) & \text{se $n$ è dispari}
    \end{array}
  \right.
$$

## Stampa di un numero naturale

``` c++
void Nat::print() const {
  for (int i = 1; i <= SIZE; i++)
    std::cout << std::setw(DIGITS) << std::setfill('0') << digit[SIZE - i];
  std::cout << std::endl;
}
```

Per stampare un numero naturale basta stamparne tutte le cifre che lo
compongono, facendo attenzione a stampare per prima la **cifra più
significativa** (che normalmente scriviamo a sinistra) e poi via via le altre
fino a quella **meno significativa** (che normalmente scriviamo a destra).

Il manipolatore `setw` indica che desideriamo stampare le cifre facendo uso di
`DIGITS` cifre decimali, mentre il manipolatore `setfill` indica che vogliamo
riempire eventuali spazi vuoti con il carattere `0`. Questi manipolatori sono
definiti nel modulo `iomanip` che abbiamo importato all'inizio del programma.

Notare che la correttezza di questo metodo dipende dal fatto che `BASE` sia una
potenza di 10.

## Esercizi

1. Realizzare una funzione `Nat fact(int n)` che calcoli il fattoriale di `n`.
   Quanto fa mille fattoriale?
2. Realizzare una funzione `Nat fibo(int n)` che calcoli il numero di Fibonacci
   con indice `n`, ricordando che la sequenza di Fibonacci è composta dai numeri
   $0,1,1,2,3,5,8,\dots$ Qual è il numero di Fibonacci con indice 1000000?
3. Modificare `print` in modo tale che il metodo non stampi le cifre `0` inutili.
4. Aggiungere un metodo `bool zero()` per determinare se il numero naturale su
   cui viene invocato è zero oppure no.
5. Aggiungere un metodo `Nat pred()` per calcolare il predecessore di un numero
   naturale. Se il numero è 0, il risultato sarà il numero naturale più grande
   rappresentabile con `SIZE` cifre in base `BASE`.
6. Usando `pred` e `zero`  definire una funzione iterativa  `Nat sub(Nat x, Nat
   y)` per sottrarre `y` da `x` facendo decrementi successivi. Usare questa
   funzione per calcolare la differenza tra il fattoriale di 10 e il fattoriale
   di 9. Il risultato deve essere 3265920.
