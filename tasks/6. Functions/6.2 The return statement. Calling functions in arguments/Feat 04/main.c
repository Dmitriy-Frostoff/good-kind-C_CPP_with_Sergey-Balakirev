/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191303/step/6?unit=1204291}
 *
 */

#include <stdio.h>

#define MAX_SAFE_INTEGER 2147483647

/**
 *  @brief Check the two integers that every of them is \
 *    in range [-2 147 483 648; 2 147 483 647]
 *
 *  @param {int} num1 - integer for check that in range [-2 147 483 648; 2 147
 * 483 647]
 *  @param {int} num2 - integer for check that in range [-2 147 483 648; 2 147
 * 483 647]
 *
 *  @return {int} - 1 (all integers are in range)
 *  @return {int} - 0 (some integers are out of range)
 *
 *  @example
 *    is_safe_integer(2, 3) => 1
 *    is_safe_integer(-2, 3) => 1
 *    is_safe_integer(2, 2147483648) => 0
 *    is_safe_integer(-2147483649, 1) => 0
 */
int is_safe_integer(int num1, int num2) {
  if ((num1 < -MAX_SAFE_INTEGER - 1 || num1 > MAX_SAFE_INTEGER) ||
      (num2 < -MAX_SAFE_INTEGER - 1 || num2 > MAX_SAFE_INTEGER)) {
    return 0;
  }

  return 1;
}

double get_mean2(int num_1, int num_2) {
  double res = (num_1 + num_2) / (double)2;
  return res;
}

int main(void) {
  int num_1 = 0;
  int num_2 = 0;

  if (scanf("%d %d", &num_1, &num_2) != 2 || !is_safe_integer(num_1, num_2)) {
    puts("expected two integers each in range [-2 147 483 648; 2 147 483 647]");
    return 0;
  }

  printf("%.1f\n", get_mean2(num_1, num_2));
  return 0;
}
