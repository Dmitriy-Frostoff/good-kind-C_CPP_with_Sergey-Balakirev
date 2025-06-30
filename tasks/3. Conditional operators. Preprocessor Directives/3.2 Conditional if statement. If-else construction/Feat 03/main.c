/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191260/step/5?unit=1204231}
 *
 */

#include <stdio.h>

int main(void) {
  int m;
  int n;
  int divisionRemainder;
  if (scanf("%d, %d", &m, &n) != 2) {
    printf("Input error.");
    return 0;
  }

  divisionRemainder = m % n;

  if (divisionRemainder == 0) {
    printf("%d", m / n);

    return 0;
  }

  printf("division error");

  return 0;
}
