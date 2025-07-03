/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191302/step/6?unit=1204290}
 *
 */

#include <stdio.h>

/**
 *  @brief get @link{n} in the power @link{m}
 *
 *  Get the integer @link{n} raised in the power of integer @link{m}
 *
 *  @param {int} n - integer (max: 2 ** 31 - 1 => 2 147 483 647)
 *  @param {int} m - integer (max: 2 ** 31 - 1)
 *
 *  @return {int} - the result of n ** m
 *  @throw "`m` must be >= 0"
 *
 *  @example
 *    pow_n(2, -1) => "`m` must be >= 0"
 *    pow_n(2, 0) => 1
 *    pow_n(2, 4) => 16
 *    pow_n(2 147 483 647, 2) => ?? unpredictable behavior
 */
int pow_n(int n, int m) {
  int res = 1;

  if (m < 0) {
    puts("`m` must be >= 0");
    return 0;
  }

  if (m == 0) {
    return 1;
  }

  while (m > 0) {
    res *= n;
    m -= 1;
  }

  return res;
}

int main(void) {
  printf("%d\n", pow_n(2, 4));
  return 0;
}
