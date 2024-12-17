
#include <iomanip>
#include <iostream>

const int BASE   = 1000000000;
const int DIGITS = log10(BASE);
const int SIZE   = 500;

class Nat {
private:
  int digit[SIZE];

public:
  Nat(int n = 0);
  Nat add(const Nat& n) const;
  Nat mul(int n) const;
  Nat pow(int n) const;
  Nat pred() const;
  bool zero() const;
  void print() const;
};

Nat::Nat(int n) {
  for (int i = 0; i < SIZE; i++) {
    digit[i] = n % BASE;
    n /= BASE;
  }
}

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

Nat Nat::mul(int n) const {
  if (n == 0) return Nat(0);
  else return this->add(this->mul(n - 1));
}

// ESERCIZIO 1

Nat fact(int n) {
  if (n == 0) return Nat(1);
  else return fact(n - 1).mul(n);
}

// ESERCIZIO 2

Nat fibo(int n) {
  if (n == 0) return Nat(0);
  else if (n == 1) return Nat(1);
  else return fibo(n - 1).add(fibo(n - 2));
}

// ESERCIZIO 3

void Nat::print() const {
  bool zero = true;
  for (int i = 1; i <= SIZE; i++)
    if (zero && digit[SIZE - i] > 0) {
      zero = false;
      std::cout << digit[SIZE - i];
    } else if (!zero) {
      std::cout << std::setw(DIGITS) << std::setfill('0') << digit[SIZE - i];
    }
  if (zero) std::cout << "0";
}

// ESERCIZIO 4

bool Nat::zero() const {
  for (int i = 0; i < SIZE; i++)
    if (digit[i] != 0) return false;
  return true;
}

// ESERCIZIO 5

Nat Nat::pred() const {
  Nat r;
  int i = 0;
  while (i < SIZE && digit[i] == 0) {
    r.digit[i] = BASE - 1;
    i++;
  }
  if (i < SIZE) {
    r.digit[i] = digit[i] - 1;
    i++;
    while (i < SIZE) {
      r.digit[i] = digit[i];
      i++;
    }
  }
  return r;
}

// ESERCIZIO 6

Nat mul(const Nat& x, Nat y) {
  Nat r;
  while (!y.zero()) {
    r = r.add(x);
    y = y.pred();
  }
  return r;
}

// ESERCIZIO 7

Nat pow(const Nat& x, int n) {
  return n == 0 ? Nat(1) : mul(x, pow(x, n - 1));
}

// ESERCIZIO 8

Nat sub(Nat x, Nat y) {
  while (!y.zero()) {
    x = x.pred();
    y = y.pred();
  }
  return x;
}

int main() {
  Nat r = fact(1000);
  pow(Nat(2), 100).print();
}
