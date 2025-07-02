/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191285/step/7?unit=1204273}
 *
 */

#include <stdio.h>

int main(void) {
  unsigned short n;

  if (scanf("%hu", &n) != 1) {
    printf("expected one positive integer");

    return 0;
  }

  for (int i = 0; i < n; i += 1) {
    printf("=");
  }

  return 0;
}
