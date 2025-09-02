#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define RES_GCD_SIZE 3

long long *common_gcd(long long first_coof, long long second_coof) {
  if (first_coof < second_coof) {
    return NULL;
  }
  long long *res = malloc(sizeof(long long) * RES_GCD_SIZE);
  // начальные значения
  long long V[RES_GCD_SIZE] = {second_coof, 0, 1};
  long long tmp[RES_GCD_SIZE];
  res[0] = first_coof;
  res[1] = 1;
  res[2] = 0;
  while (V[0] != 0) {
    long long q = res[0] / V[0];
    tmp[0] = res[0] % V[0];
    tmp[1] = res[1] - V[1] * q;
    tmp[2] = res[2] - V[2] * q;
    memcpy(res, V, sizeof(long long) * RES_GCD_SIZE);
    memcpy(V, tmp, sizeof(long long) * RES_GCD_SIZE);
  }
  return res;
}

int main() {
  long long x = 23423443, y = 34324;
  long long *solution = common_gcd(x, y);
  if (solution == NULL) {
    printf("error: a >= b\n");
  } else {
    printf("solution: x = %lld; y = %lld; gcd = %lld\n", solution[1],
           solution[2], solution[0]);
  }
  free(solution);
  return 0;
}