/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191292/step/10?unit=1204280}
 *
 * Decalre array with name 'ar_rnd' of type 'short' and of 64 elements length.
 * Initialize the ar_rnd than from INPUT: get 5 integers (in one line, space
 * separated) and assign them in order to first 5 elements of 'ar_rnd'
 *
 */

#include <stdio.h>

int main(void) {
  short ar_rnd[64] = {0};

  /**
   * @example
   *    ar_rnd[64] and 0 -1 2 -3 4 => {0 x 64} and 0 -1 2 -3 4 =>
   *        => {0, -1, 2, -3, 4, 0 x 59}
   */
  for (unsigned char i = 0; i < 5; i += 1) {
    if (scanf("%hd ", &ar_rnd[i]) != 1) {
      printf("expected 5 space separated integers (e.g. 0 1 2 3 4)");
      return 0;
    }
  }

  /**
   * макроопределение для тестирования
   * (не убирать и должно идти непосредственно перед return 0)
   */
  __ASSERT_TESTS__
  return 0;
}
