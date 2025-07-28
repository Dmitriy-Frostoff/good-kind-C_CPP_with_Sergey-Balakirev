#include "./utils.h"

/**
 *  @brief Count rectangle square via coordinates of two points
 *
 *  @note ! Impure function !
 *  - implicit dependency on @type{POINT}
 *
 *  @param {const POINT *} obj_1 - address of the first point
 *  @param {const POINT *} obj_2 - address of the second point
 *
 *  @return {int} - counted rectangle square
 *  @throw if @link{rect_width} or @link{rect_height} is non - negative
 *
 *  @example
 *    POINT pt_1 = {8 11};
 *    POINT pt_2 = {18 44};
 *
 *    int res = rect_square(&pt_1, &pt_2);
 *    res = 330;
 *
 *    POINT pt_1 = {18 44};
 *    POINT pt_2 = {8 11};
 *
 *    int res = rect_square(&pt_1, &pt_2);
 *    Error(rect_square() function): rect_width is non - negative integer
 *    @note rect_width = 8 - 18 = -10;
 *    Error(rect_square() function): rect_height is non - negative integer
 *    @note rect_height = 11 - 44 = -33;
 *    res = -1;
 *
 */
int rect_square(const POINT *obj_1, const POINT *obj_2) {
  int rect_width = obj_2->x - obj_1->x;
  int rect_height = obj_2->y - obj_1->y;

  if (rect_width <= 0) {
    puts("Error(rect_square() function): rect_width is non - negative integer");
    return -1;
  }
  if (rect_height <= 0) {
    puts(
        "Error(rect_square() function): rect_height is non - negative integer");
    return -1;
  }

  int rect_square = rect_width * rect_height;

  return rect_square;
}
