/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191266/step/5?unit=1204237}
 *
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  unsigned int N;
  unsigned int num1;
  unsigned int num2;
  unsigned int num3;
  unsigned int num4;
  unsigned int num5;
  unsigned int num6;
  unsigned int num7;

  if (scanf("%d", &N) != 1) {
    printf("Expected positive integer!");

    return 0;
  }

  num1 = rand() % (N + 1);
  num2 = rand() % (N + 1);
  num3 = rand() % (N + 1);
  num4 = rand() % (N + 1);
  num5 = rand() % (N + 1);
  num6 = rand() % (N + 1);
  num7 = rand() % (N + 1);

  printf("%u %u %u %u %u %u %u", num1, num2, num3, num4, num5, num6, num7);

  return 0;
}
