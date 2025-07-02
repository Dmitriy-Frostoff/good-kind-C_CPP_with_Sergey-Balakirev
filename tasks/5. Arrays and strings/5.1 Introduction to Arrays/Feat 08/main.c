/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191291/step/10?unit=1204279}
 *
 */

#include <stdio.h>

int main(void) {
  int digits[5];

  for (unsigned short i = 0; i < 5; i += 1) {
    if (scanf("%d ", &digits[i]) != 1) {
      printf(
          "expected 5 integers space separated in the input like: 0 1 2 3 4");
      return 0;
    }
    printf("%d ", digits[i]);
  }

  /**
   * макроопределение для тестирования
   * (не убирать и должно идти непосредственно перед return 0)
   */
  __ASSERT_TESTS__
  return 0;
}
