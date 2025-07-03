/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191304/step/5?unit=1204292}
 *
 */

#include <math.h>
#include <stdio.h>

double get_geom(int num_1, int num_2);

/**
 *  @brief get two integers (both >= 0 or both < 0) and print to console their
 *    geometric mean rounded to hundreds
 *
 *  @return {int} - 0, everything OK
 *  @throw return NAN if num_1 * num_2 < 0 (sqrt(num_1 * num_2 < 0) => NAN)
 *
 *  @example
 *    5, 7 => 5.92
 *    1 0 => "expected two integers comma separated, each in range
 *    [-2 147 483 648; 2 147 483 647; 2 147 483 647]"
 *    1, => "expected two integers comma separated, each in range
 *    [-2 147 483 648; 2 147 483 647; 2 147 483 647]"
 */
int main(void) {
  int a;
  int b;

  if (scanf("%d, %d", &a, &b) != 2) {
    puts("expected two integers comma separated, each in range [-2 147 483 "
         "648; 2 147 483 647]");
    return 0;
  }

  printf("%.2f\n", get_geom(a, b));

  return 0;
}

/**
 *  @brief Count the geometric mean of two integers (!)(both >= 0 or both < 0)
 *
 *  @param {int} num_1 -  integer in range [-2 147 483 648; 2 147 483 647]
 *  @param {int} num_2 - integer in range [-2 147 483 648; 2 147 483 647]
 *
 *  @return {double | NAN} - geometric mean of two integers or NAN
 *  @throw message and program exit if num_1 * num_2 < 0
 *
 *   @example
 *    get_geom(5, 7) => 5.916080
 *    get_geom(-5, 12) => "arguments must be >= 0 or both < 0"
 */
double get_geom(int num_1, int num_2) {
  if (num_1 * num_2 < 0) {
    puts("arguments must be >= 0 or both < 0");
    return NAN;
  }

  int num_quantity = 2;
  double res = pow((double)(num_1 * num_2), (1.0 / num_quantity));
  return res;
}
