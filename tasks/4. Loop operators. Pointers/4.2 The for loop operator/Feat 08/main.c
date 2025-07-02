/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191285/step/10?unit=1204273}
 *
 */

#include <stdio.h>

int main(void) {
  unsigned short n;
  unsigned short sum = 0;

  if (scanf("%hu", &n) != 1 || n < 1) {
    printf("expected one positive integer");

    return 0;
  }

  for (unsigned short i = 2; i < n; i += 1) {
    if (i % 3 == 0 || i % 5 == 0) {
      sum += i;
    }
  }

  printf("%u", sum);

  return 0;
}
