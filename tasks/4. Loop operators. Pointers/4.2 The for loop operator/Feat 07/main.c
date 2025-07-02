/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191285/step/9?unit=1204273}
 *
 */

#include <stdio.h>

int main(void) {
  unsigned short n;

  if (scanf("%hu", &n) != 1 || n < 1) {
    printf("expected one positive integer");

    return 0;
  }

  for (unsigned short i = 1; i <= n; i += 1) {
    if (n % i == 0) {
      printf("%u ", i);
    }
  }

  return 0;
}
