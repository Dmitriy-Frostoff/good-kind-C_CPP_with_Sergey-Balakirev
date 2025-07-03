/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191293/step/6?unit=1204281}
 *
 */

#include <stdio.h>

int main(void) {
  char buffer[128];
  char *ptr_ar = buffer;

  char buff_1_length = sizeof(buff_1) / sizeof(*buff_1);
  char buff_2_length = sizeof(buff_2) / sizeof(*buff_2);

  /**
   * @example
   *    {undef x 128} and {0, 1, 2} => {0, 1, 2, undef x 125}
   */
  for (char i = 0; i < buff_1_length; i += 1) {
    *(ptr_ar + i) = buff_1[i];
  }

  /**
   * @example
   *    {0, 1, 2, undef x 125} and {3, 4, 5, 6}
   *        => {0, 1, 2, 3, 4, 5, 6, undef x 121}
   */
  for (char i = 0; i < buff_2_length; i += 1) {
    // ptr_ar + buff_1_length => to start
    // from the next num after all the copied of buff_1
    *((ptr_ar + buff_1_length) + i) = buff_2[i];
  }

  /**
   * макроопределение для тестирования
   * (не убирать и должно идти непосредственно перед return 0)
   */
  __ASSERT_TESTS__
  return 0;
}
