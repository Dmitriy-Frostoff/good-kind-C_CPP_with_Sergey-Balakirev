/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191260/step/10?unit=1204231}
 *
 */

#include <stdio.h>

int main(void) {
  int a;
  int b;
  int c;
  int d;

  if (scanf("%d %d %d", &a, &b, &c) != 3) {
    printf("must be inputed three numbers!");

    return 0;
  }

  d = b * b - 4 * a * c;

  if (d >= 0) {
    printf("real roots exist");

    return 0;
  }

  printf("%d", d);

  return 0;
}
