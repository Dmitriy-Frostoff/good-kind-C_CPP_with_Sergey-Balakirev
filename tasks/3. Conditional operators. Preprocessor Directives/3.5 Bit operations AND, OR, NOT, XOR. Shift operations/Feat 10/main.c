/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191265/step/12?unit=1204235}
 *
 */

#include <stdio.h>

int main(void) {
  unsigned short num1;
  unsigned short num2;
  unsigned short res;

  if (scanf("%hu %hu", &num1, &num2) != 2) {
    printf("expected two positive integers");

    return 0;
  }

  res = (num1 >> 1) * (num2 >> 1);

  printf("%u", res);

  return 0;
}
