/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191253/step/12?unit=1204224}
 *
 */

#include <stdio.h>

int main(void) {
  unsigned int rect_width = 640;
  unsigned int rect_height = 480;
  unsigned int w = 1;
  unsigned int h = 1;
  scanf("%d; %d", &w, &h);

  // count quantity of w and h to rect_width and rect_height correspondingly
  // then mult the results
  unsigned int quantityOfW = rect_width / w;
  unsigned int quantityOfH = rect_height / h;

  unsigned int result = quantityOfW * quantityOfH;

  printf("%d", result);

  return 0;
}
