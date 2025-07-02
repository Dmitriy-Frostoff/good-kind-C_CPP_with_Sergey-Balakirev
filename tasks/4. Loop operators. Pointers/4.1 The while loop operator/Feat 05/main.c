/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191284/step/7?unit=1204272}
 *
 */

#include <stdio.h>

int main(void) {
  unsigned int num;
  unsigned int currentRemainder = 0;
  unsigned int range = 10;
  unsigned int sum = 0;

  if (scanf("%u", &num) != 1 || num < range) {
    printf("expected one positive integer >= 10");

    return 0;
  }

  /**
   * e.g. num 123
   * currentRemainder => 3
   * num => 12 (int / int => similar to trunc(int / int))
   * sum => 0 + 3
   * ...
   * till num = 1 => 1 / 10 => 0
   */
  while (num) {
    currentRemainder = num % range;
    num = num / range;
    sum += currentRemainder;
  }

  printf("%d\n", sum);

  return 0;
}
