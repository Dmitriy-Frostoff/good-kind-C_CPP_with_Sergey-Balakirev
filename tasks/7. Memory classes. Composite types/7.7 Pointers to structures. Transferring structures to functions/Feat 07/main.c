/**
 *  The task description is at
 *  @link{https://stepik.org/lesson/1191316/step/9?unit=1204304}
 *
 */

#include "./config.h"
#include "./utils.h"

int main(void) {
  POINT pt_1 = {};
  POINT pt_2 = {};
  int counted_square = 0;

  // get coordinates for points
  if (get_input_data(&pt_1, &pt_2) == -1) {
    return 1;
  }

  // count square of the rectangle
  counted_square = rect_square(&pt_1, &pt_2);

  if (counted_square == -1) {
    return 1;
  }

  // print the @link{counted_square}
  printf("%d\n", counted_square);

  return 0;
}
