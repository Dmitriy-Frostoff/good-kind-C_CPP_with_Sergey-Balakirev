/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191284/step/5?unit=1204272}
 *
 */

#include <stdio.h>

int main(void) {
  int num;

  while (scanf("%d ", &num) && num != 0) {
    printf("%d ", num * num);
  }

  return 0;
}
