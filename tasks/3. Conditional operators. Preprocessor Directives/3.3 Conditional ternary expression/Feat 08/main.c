/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191262/step/10?unit=1204233}
 *
 */

#include <stdio.h>

int main(void) {
  unsigned int a;
  unsigned int b;
  unsigned int h;
  double square;

  if (scanf("%u, %u, %u", &a, &b, &h) != 3) {
    printf("expected three positive integers each in range [1: 100] !");

    return 0;
  }

  square = (a + b) / 2.0 * h;

  printf("%.1f", square);

  return 0;
}
