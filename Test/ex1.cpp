
// restituisce true se n non ha divisori da k a n - 1
bool no_divisors(int n, int k) {
  if (k == n) return true;
  else return n % k != 0 && no_divisors(n, k + 1);
}

bool is_prime(int n) {
  return n > 1 && no_divisors(n, 2);
}

bool there_are_primes(int data[], int n, int i) {
  return i == n || (!is_prime(data[i]) && there_are_primes(data, n, i + 1));
}
