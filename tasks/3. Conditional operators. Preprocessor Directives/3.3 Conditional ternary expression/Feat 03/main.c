/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191262/step/5?unit=1204233}
 *
 */

#include <stdio.h>

int main(void) {
  int x;

  if (scanf("%d", &x) != 1) {
    printf("must be provided one number!");

    return 0;
  }

  printf("%d", x > 0 ? x : 0);

  return 0;
}
