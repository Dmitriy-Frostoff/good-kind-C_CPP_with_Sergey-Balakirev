/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191303/step/9?unit=1204291}
 *
 */

#include <stdio.h>

/**
 *  @brief check that 'real number' is in range
 *    ( @link{range_min}; @link{range_max} )
 *
 *  @param {double} num - real number to check
 *  @param {double} range_min - min value of range
 *  @param {double} range_max - max value of range
 *
 *  @return {int} - 1 , @link{num} is in range
 *  @return {int} - 0 , @link{num} is out of range
 *
 *  @example
 *    is_range(1.0, -2.5; 3.5) => 1
 *    is_range(-5.0, -2.5; 3.5) => 0
 */
int is_range(double num, double range_min, double range_max) {
  if (num > range_min && num < range_max) {
    return 1;
  }
  return 0;
}

#define RANGE_MIN (-2.5)
#define RANGE_MAX 3.5

/**
 *  @brief print the 'real numbers' (rounded to tenths)
 *   that are out of range (-2.5; 3.5)
 *
 *  @return {int} - 0, everything OK
 *
 *  @example
 *     >>> 0.54 0.1 -4.3 -2.1 10.56 7.43 -5.4 0.05 =>
 *      -4.3 10.6 7.4 -5.4
 */
int main(void) {
  double x;

  while (scanf("%lf", &x) == 1) {
    if (!is_range(x, RANGE_MIN, RANGE_MAX)) {
      printf("%.1lf ", x);
    }
  }

  return 0;
}
