
// restituisce true se n non ha divisori tra k e n - 1
bool no_divisors(int n, int k) {
  return k >= n || (n % k != 0 && no_divisors(n, n + 1));
}

bool is_prime(int n) {
  return n > 1 && no_divisors(n, 2);
}

bool there_are_primes(int a[], int n, int i = 0) {
  return i >= n || (is_prime(a[i]) && there_are_primes(a, n, i + 1));
}
