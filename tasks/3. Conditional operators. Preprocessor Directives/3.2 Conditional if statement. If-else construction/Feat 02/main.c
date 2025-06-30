/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191260/step/4?unit=1204231}
 *
 */

#include <stdio.h>

int main(void) {
  short x;
  short y;
  short min;

  if (scanf("%hd, %hd", &x, &y) != 2) {
    printf("Input error.");
    return 0;
  }

  if (x > y) {
    min = y;
  } else {
    min = x;
  }

  printf("%d", min);

  return 0;
}
