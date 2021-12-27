// time - O(2^n)
// space - O(n)

int fib(int n) {
    if (n > 1) {
        return fib(n - 1) + fib(n -2);
    }
    return n;
}


// time - O(1)
// space - O(1)

int binetFib(int n) {
  double phi = (sqrt(5) + 1) / 2;
  return round(pow(phi, n) / sqrt(5));
}
