/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191286/step/12?unit=1204274}
 *
 */

#include <stdio.h>

int main(void) {
  unsigned short m;
  unsigned short n;
  unsigned short k;
  double sum = 0.0;
  double constPartOfCounting;

  if (scanf("%hu %hu %hu", &m, &n, &k) != 3 || m <= 0 || n <= 0 || k <= 0) {
    printf("expected three natural numbers");
    return 0;
  }

  constPartOfCounting = 1 / (double)(n + m + k);

  for (unsigned short i = 1; i <= m; i += 1) {
    for (unsigned short j = 1; j <= n; j += 1) {
      for (unsigned short t = 1; t <= k; t += 1) {
        sum += constPartOfCounting *
               (j * j / (double)((i + t) * (i + t) * (i + t) - t));
      }
    }
  }

  printf("%.4f", sum);

  return 0;
}
