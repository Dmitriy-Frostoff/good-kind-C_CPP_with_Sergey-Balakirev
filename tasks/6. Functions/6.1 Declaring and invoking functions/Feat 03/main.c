/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191302/step/5?unit=1204290}
 *
 */

#include <stdio.h>

/**
 *  @brief
 *    Get the factorial of the @link{num}
 *
 *  @param {int} num - integer (max: 2 ** 31 - 1)
 *  @return {int} - factorial of the @link{num}
 *
 *  @example
 *    fact(3) => 6
 *    fact(6) => 720
 *    fact(-2) => -1
 *    fact(-100) => -1
 *    fact(0) => 1
 */
int fact(int num) {
  int res = 1;

  if (num == 0) {
    return 1;
  }

  if (num < 0) {
    return -1;
  }

  while (num - 1 > 0) {
    res *= num;
    num -= 1;
  }

  return res;
}

int main(void) {
  printf("%d\n", fact(6));
  return 0;
}
