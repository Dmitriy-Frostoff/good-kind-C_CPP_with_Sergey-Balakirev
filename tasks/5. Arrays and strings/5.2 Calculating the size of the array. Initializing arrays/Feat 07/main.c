/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191292/step/9?unit=1204280}
 *
 * Decalre the array of type 'long' with name 'digits' and of 128 elements
 * length. Initialize the 'digits' array so that:
 *  digits[16] = 4
 *  digits[32] = 5
 *  digits[64] = 6
 *  and all the others elements are 0 (zero)
 *
 */

#include <stdio.h>

int main(void) {
  long digits[128] = {[16] = 4, [32] = 5, [64] = 6};

  /**
   * макроопределение для тестирования
   * (не убирать и должно идти непосредственно перед return 0)
   */
  __ASSERT_TESTS__
  return 0;
}
