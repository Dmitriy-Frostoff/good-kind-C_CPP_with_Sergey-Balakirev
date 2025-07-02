/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191287/step/9?unit=1204275}
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

  // break won't end up all the for cycles! (only inner one)
  // sum will be
  /**
   * @example
   *    m = 10, n = 10 =>
   *        45 90 134 176 215 250 280 304 321 330 330
   *    but currently will be printed only final result => 330
   */
  for (unsigned short i = 0; i <= n; i += 1) {
    for (unsigned short j = 0; j <= m; j += 1) {
      if (i + j >= 10) {
        break;
      }

      sum += i + j;
    }
  }

  printf("%u", sum);

  return 0;
}
