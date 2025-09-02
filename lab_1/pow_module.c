#include <math.h>
#include <stdio.h>

long long pow_by_module(long long a, long long exp, long long module) {
  long long res = 1;
  long long dp = a;
  for (int i = 0; i <= log(exp); i++) {
    if ((exp >> i) & 1) {
      res = res * dp % module;
    }
    dp = dp * dp % module;
  }
  return res;
}

int main() {
  long long digit = 2;
  long long exp = 100;
  long long module = 13;
  printf("%lld\n", pow_by_module(digit, exp, module));
}