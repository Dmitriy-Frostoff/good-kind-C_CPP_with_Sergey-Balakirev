/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191286/step/6?unit=1204274}
 *
 */

#include <stdio.h>

int main(void) {
  short n;
  double i = 1.0;
  double sum = 0.0;

  if (scanf("%hd", &n) != 1 || n <= 0) {
    printf("expected one positive integer");
    return 0;
  }

  do {
    sum += 1 / i;
    i += 1;
  } while (i <= n);

  printf("%.2f\n", sum);

  return 0;
}
