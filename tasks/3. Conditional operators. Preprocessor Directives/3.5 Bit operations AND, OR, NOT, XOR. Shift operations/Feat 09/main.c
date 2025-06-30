/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191265/step/11?unit=1204235}
 *
 */

#include <stdio.h>

int main(void) {
  unsigned int num;
  unsigned int res;

  if (scanf("%u", &num) != 1) {
    printf("expected one positive integer!");

    return 0;
  }

  res = num << 3;

  printf("%u", res);

  return 0;
}
