/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191287/step/6?unit=1204275}
 *
 */

#include <stdio.h>

int main(void) {
  unsigned short n;

  if (scanf("%hu", &n) != 1 || n <= 0) {
    printf("expected one natural number");
    return 0;
  }

  for (unsigned short i = 1; i < n; i += 1) {
    if (i * i >= n) {
      break;
    }

    printf("%u ", i);
  }

  return 0;
}
