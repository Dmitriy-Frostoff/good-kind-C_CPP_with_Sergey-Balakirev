/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191253/step/4?unit=1204224}
 *
 */

#include <stdio.h>

int main(void) {
  int angle;
  scanf("%d", &angle);

  int res = angle % 360;
  printf("%d", res);

  return 0;
}
