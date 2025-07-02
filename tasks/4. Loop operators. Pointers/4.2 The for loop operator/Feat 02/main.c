/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191285/step/4?unit=1204273}
 *
 */

#include <stdio.h>

int main(void) {
  int s = 0;
  int n = 0;

  if (scanf("%d", &n) != 1) {
    printf("expected one integer");

    return 0;
  }

  for (int i = 6; i <= n + 1; i += 1) {
    s += i;
  }

  printf("%d", s);

  return 0;
}
