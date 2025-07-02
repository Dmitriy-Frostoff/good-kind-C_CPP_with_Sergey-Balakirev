/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191291/step/8?unit=1204279}
 *
 * Declare array with name 'buffer' with 1024 elements length (of type short).
 * Assign the first array element ('buffer'[0]) with value 13
 *
 */

#include <stdio.h>

int main(void) {
  short buffer[1024];

  buffer[0] = 13;

  /**
   * макроопределение для тестирования
   * (не убирать и должно идти непосредственно перед return 0)
   */
  __ASSERT_TESTS__
  return 0;
}
