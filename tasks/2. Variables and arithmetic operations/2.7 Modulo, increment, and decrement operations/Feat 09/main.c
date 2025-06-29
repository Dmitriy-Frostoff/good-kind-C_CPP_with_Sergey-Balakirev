/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191253/step/11?unit=1204224}
 *
 */

#include <stdio.h>

int main(void) {
  int h;
  int w;

  scanf("%d, %d", &h, &w);
  printf("%d", ++h * ++w);

  return 0;
}
