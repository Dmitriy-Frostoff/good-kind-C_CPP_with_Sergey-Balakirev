/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191265/step/10?unit=1204235}
 *
 */

#include <stdio.h>

int main(void) {
  unsigned short num;
  unsigned short res;

  if (scanf("%hu", &num) != 1) {
    printf("expected one positive integer!");

    return 0;
  }

  res = num >> 2;

  printf("%d", res);

  return 0;
}
