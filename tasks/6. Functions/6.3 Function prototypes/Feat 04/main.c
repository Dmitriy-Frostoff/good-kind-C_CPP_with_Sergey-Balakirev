/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191304/step/6?unit=1204292}
 *
 */

#include <stdio.h>

int calc_rect(int length_a, int length_b, int operation_type);

/**
 *  @brief get three positive intgers and print to console the rectangle area or
 *    the rectangle perimeter
 *
 *  Expect three integers, where first: rectangle width,
 *  second: rectangle height, third: type of operation => 1 means calc the area,
 *  another - count perimeter
 *
 *  @throw if not three positive integers were given
 *
 *  @example
 *    87, 32, 1 => 2784
 *    87, 32, 2 => 238
 *    5, 10 => "expected three positive integers comma separated"
 *    -15, 12, 1 => "expected three positive integers comma separated"
 */
int main(void) {
  int a;
  int b;
  int t;

  if (scanf("%d, %d, %d", &a, &b, &t) != 3 || a < 0 || b < 0 || t < 0) {
    puts("expected three positive integers comma separated");
    return 0;
  }

  printf("%d\n", calc_rect(a, b, t));

  return 0;
}

/**
 *  @brief Get the rectangle area
 *
 *  @param {int} rect_width - width of rectangle (> 0)
 *  @param {int} rect_height - height of the rectangle (> 0)
 *
 *  @return {int} - perimter of the rectangle
 *
 *  @example
 *    get_rectangle_area(5, 7) => 35
 *    get_rectangle_area(12, 8) => 96
 */
int get_rectangle_area(int rect_width, int rect_height) {
  int res = rect_width * rect_height;
  return res;
}

/**
 *  @brief Get the rectangle perimeter
 *
 *  @param {int} rect_width - width of rectangle (> 0)
 *  @param {int} rect_height - height of the rectangle (> 0)
 *
 *  @return {int} - perimter of the rectangle
 *
 *  @example
 *    get_rectangle_perimeter(5, 7) => 24
 *    get_rectangle_perimeter(12, 8) => 40
 */
int get_rectangle_perimeter(int rect_width, int rect_height) {
  int res = 2 * (rect_width + rect_height);
  return res;
}

/**
 *  @brief Get the rectangle area or perimeter
 *
 *  if @link{operation_type} = 1 => calculate and returns area,
 *  calculate perimeter otherwise
 *
 *  @param {int} length_a - width of rectangle (> 0)
 *  @param {int} length_b - height of the rectangle (> 0)
 *  @param {int} operation_type - 1 (get area) or perimeter for another integer
 *     (> 0)
 *
 *  @return {int} - calculated area or perimeter of the rectangle
 *
 *  @example
 *    calc_rect(5, 7, 1) => 35
 *      1 => area
 *    calc_rect(12, 8, 10) => 40
 *      not 1 => perimeter
 */
int calc_rect(int length_a, int length_b, int operation_type) {
  int res = 0;
  res = operation_type == 1 ? get_rectangle_area(length_a, length_b)
                            : get_rectangle_perimeter(length_a, length_b);

  return res;
}
