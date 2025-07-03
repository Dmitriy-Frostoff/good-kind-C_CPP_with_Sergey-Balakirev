/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191302/step/8?unit=1204290}
 *
 */

#include <stdio.h>

#define MAX_SAFE_INTEGER 2147483647

/**
 *  @brief Check the three integers that every of them is \
 *    in range (0; 2 147 483 647)
 *
 *  @param {type} a - integer for check that in range (0; 2 147 483 647)
 *  @param {type} b - integer for check that in range (0; 2 147 483 647)
 *  @param {type} c - integer for check that in range (0; 2 147 483 647)
 *
 *  @return {int} - 1 (all integers are in range)
 *  @return {int} - 0 (some integers are out of range)
 *
 *  @example
 *    is_safe_positive_integer(2, 3, 5) => 1
 *    is_safe_positive_integer(-2, 3, 5) => 0
 *    is_safe_positive_integer(2, 3, 2147483647) => 0
 */
int is_safe_positive_integer(int a, int b, int c) {
  if ((a <= 0 || a > MAX_SAFE_INTEGER) || (b <= 0 || b > MAX_SAFE_INTEGER) ||
      (c <= 0 || c > MAX_SAFE_INTEGER)) {
    return 0;
  }

  return 1;
}

/**
 *  @brief Check over the sides that the triangle can exist
 *
 *  @param {int} a - integer in range (0; 2 147 483 647)
 *  @param {int} b -  integer in range (0; 2 147 483 647)
 *  @param {int} c -  integer in range (0; 2 147 483 647)
 *
 *  @return {int} - 1 (triangle can exist)
 *  @return {int} - 0 (triangle can't exist)
 *
 *  @example
 *    is_triangle(3, 4, 5) => 1
 *      3 < (4 + 5) && 4 < (3 + 5) && 5 < (3 + 4)
 *    is_triangle(3, 4, 11) => 0
 */
int is_triangle(int a, int b, int c) {
  if ((a < (b + c)) && (b < (a + c)) && (c < (a + b))) {
    return 1;
  }

  return 0;
}

int main(void) {
  int length_a = 0;
  int length_b = 0;
  int length_c = 0;

  if (scanf("%d %d %d", &length_a, &length_b, &length_c) != 3 ||
      !is_safe_positive_integer(length_a, length_b, length_c)) {
    puts("expected three integers each in range (0; 2 147 483 647)");
    return 0;
  }

  printf("%d\n", is_triangle(length_a, length_b, length_c));
  return 0;
}
