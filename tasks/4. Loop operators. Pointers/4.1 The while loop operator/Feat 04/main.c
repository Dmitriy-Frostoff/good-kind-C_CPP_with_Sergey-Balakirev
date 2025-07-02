/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191284/step/6?unit=1204272}
 *
 */

#include <stdio.h>

int main(void) {
  unsigned int n;
  unsigned int num = 1;
  double sum = 0;

  if (scanf("%u", &n) != 1) {
    printf("expected one positive integer");

    return 0;
  }

  while (num <= n) {
    sum += 1 / (double)(num * num);
    num++;
  }

  printf("%.3f", sum);

  return 0;
}
