/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191258/step/13?unit=1204229}
 *
 */

#include <stdio.h>

int main(void) {
  int rect_width = 640;
  int rect_height = 480;
  int w = 1;
  int h = 1;

  int quantityOfRectOverWidth;
  int quantityOfRectOverHeight;
  int quantityOfExistingRectWithWH;
  int quantityOfRectOverWidthWithFake;
  int quantityOfRectOverHeightWithFake;
  int quantityOfAllRect;
  int quantityOfLesserRectangles;

  scanf("%d; %d", &w, &h);

  // count the quantity of exsiting rectangles with w and h in the area
  quantityOfRectOverWidth = rect_width / w;
  quantityOfRectOverHeight = rect_height / h;
  quantityOfExistingRectWithWH =
      quantityOfRectOverWidth * quantityOfRectOverHeight;

  /**
   * count the quantity of all rectangles with w and h
   * (with lesser rectangles too if exist) in the area
   * (i.e. including one with dimensions that are less than w or h)
   * e.g. rect_width % w != 0 (output: 1, i.e. true) means is to add one more
   * rectangle or not?
   */
  quantityOfRectOverWidthWithFake = rect_width / w + (rect_width % w != 0);
  quantityOfRectOverHeightWithFake = rect_height / h + (rect_height % h != 0);
  quantityOfAllRect =
      quantityOfRectOverWidthWithFake * quantityOfRectOverHeightWithFake;

  // count quantity of lesser rectangles => all the rectangles - existing one
  quantityOfLesserRectangles = quantityOfAllRect - quantityOfExistingRectWithWH;

  printf("%d\n", quantityOfLesserRectangles);

  return 0;
}
