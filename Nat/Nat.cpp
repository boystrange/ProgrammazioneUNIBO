
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
  int co = 0;
  for (int i = 0; i < SIZE; i++) {
    int s = digit[i] + n.digit[i] + co;
    r.digit[i] = s % BASE;
    co = s / BASE;
  }
  return r;
}

Nat Nat::mul(int n) const {
  if (n == 0) return Nat(0);
  else if (n % 2 == 0) {
    Nat r = mul(n / 2);
    return r.add(r);
  } else return add(mul(n - 1));
}

// ESERCIZIO 1

Nat fact(int n) {
  if (n == 0) return Nat(1);
  else return fact(n - 1).mul(n);
}

// ESERCIZIO 2

Nat fibo(int k) {
  Nat m(0);
  Nat n(1);
  while (k > 0) {
    Nat t = m.add(n);
    m = n;
    n = t;
    k--;
  }
  return m;
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
  std::cout << std::endl;
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

Nat sub(const Nat& x, const Nat& y) {
  Nat a = x;
  Nat b = y;
  while (!b.zero()) {
    a = a.pred();
    b = b.pred();
  }
  return a;
}

int main() {
  sub(fact(10), fact(9)).print();
}
