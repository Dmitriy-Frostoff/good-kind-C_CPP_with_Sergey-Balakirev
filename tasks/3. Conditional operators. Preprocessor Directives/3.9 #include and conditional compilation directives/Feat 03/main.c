/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191283/step/5?unit=1204271}
 *
 */

#include <stdio.h>

#define PERIMETR_CALC

int main(void) {
  int a;
  int b;

  if (scanf("%d, %d", &a, &b) != 2) {
    printf("Expected two positive numbers");
    return 0;
  }

#ifndef PERIMETR_CALC
  int res = a * b;

  printf("%d", res);
#else
  int res = 2 * (a + b);

  printf("%d", res);
#endif

  return 0;
}
