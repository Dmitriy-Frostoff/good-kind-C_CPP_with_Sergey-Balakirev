/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191291/step/11?unit=1204279}
 *
 * Declare two arrays with names 'ar_1' and 'ar_2' containing elements of type
 * int. The length of array 'ar_1' must be equal to TOTAL, and array 'ar_2' must
 * be twice as long (TOTAL * 2).
 *
 * Then read five integers separated by a space from
 * the INPUT: into the 'ar_1' value array (in order, starting from 'ar_1'[0]).
 * After that, copy the values of the 'ar_1' array to the 'ar_2 array'. The
 * remaining elements of the 'ar_2' array must take the value -1.
 *
 */

#include <stdio.h>

#define TOTAL 5

int main(void) {
  int ar_1[TOTAL];
  int ar_2[TOTAL * 2];

  for (unsigned char i = 0; i < TOTAL; i += 1) {
    if (scanf("%d ", &ar_1[i]) != 1) {
      printf("expected 5 integers space separated (e.g. 0 1 2 3 4)");
      return 0;
    }
  }
  /**
   * @example
   *    ar_1[5] {0, 1, 2, 3, 4},
   *    ar_2[10] {undef, undef, undef, undef, undef, undef, undef, undef, undef,
   * undef,} => ar_1[5] {0, 1, 2, 3, 4}, ar_2[10] {0, 1, 2, 3, 4, -1, -1, -1,
   * -1, -1}
   */
  for (unsigned char i = 0; i < TOTAL * 2; i += 1) {
    if (i >= TOTAL) {
      ar_2[i] = -1;
      continue;
    }

    ar_2[i] = ar_1[i];
  }

  /**
   * макроопределение для тестирования
   * (не убирать и должно идти непосредственно перед return 0)
   */
  __ASSERT_TESTS__
  return 0;
}
