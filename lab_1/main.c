#include <base_crypto.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define RANGE 100000


long long get_simple_digit(int range_min, int range_max) {
  long long res = 0;
  do {
    res = rand() % (range_max - range_min + 1) + range_min;
  } while (test_Ferma(res, 100) == 0);
  return res;
}

int get_init_data(long long *x, long long *y, char flag)  {
  if (flag == '0') {
    *y = (rand() % RANGE) + 1;
    *x = (rand() % RANGE) + *y;
  } else if (flag == '1') {
    printf("Введити коофициент при x: ");
    if (scanf("%lld", x) != 1) {
      perror("scanf: ");
      return -1;
    }
    printf("Введите коофициент при y: ");
    if (scanf("%lld", y) != 1) {
      perror("scanf: ");
      return -1;
    }
  } else if (flag == '2') {
    *y = get_simple_digit(1, RANGE);
    *x = get_simple_digit(*y+1, *y + RANGE);
  } else {
    printf("некоректный ввод\n");
  }
}

int main() {
    srand(time(NULL));
    long long digit = 13123;
    long long exp = 21314;
    long long module = 124;
    printf("быстрое возведение в степень по модулю:\n%lld ^ %lld %% %lld = %lld\n", digit, exp, module, pow_by_module(digit, exp, module));
    long long simple = 379;
    long long not_simple = 2343;
    printf("тест Ферма:\n");
    if (test_Ferma(simple, 100)) {
        printf("digit %lld is simple\n", simple);
    }
    if (!test_Ferma(not_simple, 100)) {
        printf("digit %lld is not simple\n", not_simple);
    }
    

    long long a = 23423443, b = 34324;
    printf("обобщенный gcd.\n Введите:\n0 - для рандомных коэфициентов\n1 - для ввода с клавиатуры\n2 - для рандомных простых коэфициентов\n");
    char choise;
    if (scanf("%c", &choise) != 1) {
        perror("scanf: ");
        exit(EXIT_FAILURE);
    }
    if (get_init_data(&a, &b, choise) == -1) {
      return -1;
    }

  long long *solution = common_gcd(a, b);
  if (solution == NULL) {
    printf("error: a >= b\n");
  } else {
    printf("a = %lld; b = %lld\n", a, b);
    printf("solution: x = %lld; y = %lld; gcd = %lld\n", solution[1],
           solution[2], solution[0]);
  }
  free(solution);


  return 0;
}