/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191303/step/10?unit=1204291}
 *
 */

#include <math.h>
#include <stdio.h>

/**
 *  @brief Get the length of radius vector over the two integers
 *
 *  @param {type} num_1 - integer in range [-2147483648, 2147483647]
 *  @param {type} num_2 - integer in range [-2147483648, 2147483647]
 *
 *  @return {double} - counted length
 *
 *  @example
 *    -25 78 => 81.908486
 */
double get_length(int num_1, int num_2) {
  double res = hypot((double)num_1, (double)num_2);
  return res;
}

/**
 *  @brief print (rounded to hundreds) the length of radius-vector
 *  over the two integers
 *
 *  @return {int} - 0, everything OK
 *
 *  @example
 *     >>> -25 78 => 81.91
 */
int main(void) {
  int x;
  int y;

  if (scanf("%d %d", &x, &y) != 2) {
    puts("expected two integers, each in range [-2147483648, 2147483647]");
    return 0;
  }

  printf("%.2f\n", get_length(x, y));

  return 0;
}
