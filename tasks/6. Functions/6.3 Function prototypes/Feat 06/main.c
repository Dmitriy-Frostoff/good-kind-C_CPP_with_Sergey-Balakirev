/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191304/step/8?unit=1204292}
 *
 */

#include <stdio.h>

#define PI 3.1415

double circle_len(double radius);

/**
 *  @brief get circle's radius and print to console counted circle's length
 *    (rounded to hundreds)
 *
 *  @throw if empty input or radius <= 0 were produced
 *
 *  @example
 *    3.0 => 18.85
 *    -2.0 => "radius of circle must be positive real number"
 *    '' => "radius of circle must be positive real number"
 */
int main(void) {
  double radius = 0;

  if (scanf("%lf", &radius) != 1 || radius <= 0) {
    puts("radius of circle must be positive real number");
    return 0;
  }

  printf("%.2f\n", circle_len(radius));

  return 0;
}

/**
 *  @brief get the circle length via it's radius
 *
 *  @param {double} radius - circle's radius (> 0)
 *
 *  @return {double} - circle length
 *
 *  @example
 *    circle_len(3.0) => 18.85
 *      2 * PI * 3.0 => 18.849000
 */
double circle_len(double radius) {
  return 2 * PI * radius;
}
