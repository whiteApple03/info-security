#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <base_crypto.h>
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

long long gcd(long long a, long long b){
	if(b==0)
		return a;
	return gcd(b, a%b);
}

