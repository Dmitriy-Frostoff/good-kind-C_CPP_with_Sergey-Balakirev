/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191304/step/7?unit=1204292}
 *
 */

#include <stdio.h>

int get_max(int num_1, int num_2);
int get_min(int num_1, int num_2);

/**
 *  @brief get three integers and print to console the max (t = 1)
 *  or min (t is not 1) of them
 *
 *  @throw if not three integers were given
 *
 *  @example
 *    -5, 10, 1 => 10
 *    87, 32, 2 => 32
 *    5, 10 => "expected three integers comma separated"
 */
int main(void) {
  int a;
  int b;
  int t;

  if (scanf("%d, %d, %d", &a, &b, &t) != 3) {
    puts("expected three integers comma separated");
    return 0;
  }

  printf("%d\n", t == 1 ? get_max(a, b) : get_min(a, b));

  return 0;
}

/**
 *  @brief Get the max from two integers
 *
 *  @param {int} num_1 - first integer
 *  @param {int} num_2 - second integer
 *
 *  @return {int} - max from ( @link{num_1} and @link{num_2} )
 *
 *  @example
 *    get_max(5, 10) => 10
 */
int get_max(int num_1, int num_2) {
  if (num_1 > num_2) {
    return num_1;
  }

  return num_2;
}

/**
 *  @brief Get the min from two integers
 *
 *  @param {int} num_1 - first integer
 *  @param {int} num_2 - second integer
 *
 *  @return {int} - min from ( @link{num_1} and @link{num_2} )
 *
 *  @example
 *    get_min(5, 10) => 5
 */
int get_min(int num_1, int num_2) {
  if (num_1 < num_2) {
    return num_1;
  }

  return num_2;
}
