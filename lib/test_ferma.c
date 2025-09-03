#include <stdio.h>
#include <stdlib.h>

#include <base_crypto.h>


int test_Ferma(long long p, int k) {
  if (p == 2) return 1;
  if (!(p & 1)) return 0;
  for (int i = 0; i < k; ++i) {
    long long a = (rand() % (p-2)) + 2; 
    if (gcd(a, p) != 1 || pow_by_module(a, p-1, p) != 1) {
      return 0;
    }
  }
  return 1;
}
