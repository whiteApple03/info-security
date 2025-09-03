#include <math.h>

#include <base_crypto.h>


long long pow_by_module(long long a, long long exp, long long module) {
  long long res = 1;
  long long dp = a;
  for (int i = 0; i <= log2(exp); i++) {
    if ((exp >> i) & 1) {
      res = (res * dp) % module;
    }
    dp = (dp * dp) % module;
  }
  return res; 
}