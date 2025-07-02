/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191291/step/11?unit=1204279}
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
