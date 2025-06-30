/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191263/step/9?unit=1204234}
 *
 */

#include <stdio.h>

int main(void) {
  unsigned int num;

  if (scanf("%u", &num) != 1) {
    printf("expected one positive integer similar to 1234");
    return 0;
  }

  if (num / 1000 == 3) {
    printf("yes");
    return 0;
  }

  printf("no");

  return 0;
}
