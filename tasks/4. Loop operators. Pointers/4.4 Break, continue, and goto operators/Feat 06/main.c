/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191287/step/8?unit=1204275}
 *
 */

#include <stdio.h>

int main(void) {
  unsigned short m;
  unsigned short n;
  unsigned short sum = 0;

  if (scanf("%hu %hu", &n, &m) != 2 || m <= 0 || n <= 0) {
    printf("expcted two natural numbers");
    return 0;
  }

  for (unsigned short i = 0; i <= n; i += 1) {
    for (unsigned short j = 0; j <= m; j += 1) {
      if (i + j >= 10) {
        goto printSum;
      }

      sum += i + j;
    }
  }

printSum:
  printf("%u", sum);

  return 0;
}
