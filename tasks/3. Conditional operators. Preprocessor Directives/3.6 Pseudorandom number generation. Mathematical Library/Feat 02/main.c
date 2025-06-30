/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191266/step/4?unit=1204237}
 *
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  unsigned int num1;
  unsigned int num2;
  unsigned int num3;
  unsigned int num4;

  num1 = rand();
  num2 = rand();
  num3 = rand();
  num4 = rand();

  printf("%u %u %u %u", num1, num2, num3, num4);

  return 0;
}
