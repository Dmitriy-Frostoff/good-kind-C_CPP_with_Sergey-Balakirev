/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191303/step/8?unit=1204291}
 *
 */

#include <stdio.h>

/**
 *  @brief check that 'number' is even
 *
 *  @param {int} num - integer in range [-2 147 483 648; 2 147 483 647]
 *
 *  @return {int} - 1 => number is even
 *  @return {int} - 0 => number is odd
 *
 *  @example
 *    is_even(2) => 1
 *    is_even(3) => 0
 *    is_even(-5) => 0
 *    is_even(-4) => 1
 */
int is_even(int num) {
  int res = num % 2 == 0 ? 1 : 0;
  return res;
}

int main(void) {
  int x;

  while (scanf("%d", &x) == 1) {
    if (is_even(x)) {
      printf("%d ", x);
    }
  }

  return 0;
}
