/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191294/step/6?unit=1204282}
 *
 */

#include <stdio.h>

int main(void) {
  const char TOTAL = 5;
  short marks[100];

  // always watch on index >= 0!!!
  /**
   * @example
   *    1 2 3 4 5 6 7 8 9 10 11 12 marks{} =>
   *    marks{[5 - 1] = 1}
   *    ...
   *    marks{[5 - 5] = 5} =>
   *    marks{5, 4, 3, 2, 1}
   */
  for (char i = TOTAL; i > 0; i -= 1) {
    if (scanf("%hd ", &marks[i - 1]) != 1) {
      printf("expected space separated integers");
      return 0;
    }
  }

  for (unsigned char i = 0; i < TOTAL; i += 1) {
    printf("%d ", marks[i]);
  }

  /**
   * макроопределение для тестирования
   * (не убирать и должно идти непосредственно перед return 0)
   */
  __ASSERT_TESTS__
  return 0;
}
