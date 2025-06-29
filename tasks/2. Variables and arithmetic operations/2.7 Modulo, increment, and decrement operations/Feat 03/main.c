/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191253/step/5?unit=1204224}
 *
 */

#include <stdio.h>

int main(void) {
  int rect_width = 1280;
  int rect_height = 720;
  int w = 8;
  int h = 8;
  scanf("%d; %d", &w, &h);

  int widthRemainder = rect_width % w;
  int heightRemainder = rect_height % h;
  printf("%d %d", widthRemainder, heightRemainder);

  return 0;
}
