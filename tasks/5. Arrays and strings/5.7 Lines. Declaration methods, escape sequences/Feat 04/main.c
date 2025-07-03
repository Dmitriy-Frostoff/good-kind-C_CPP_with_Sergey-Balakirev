/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191297/step/6?unit=1204285}
 *
 */

#include <stdio.h>

#define TEXT "Best string!"

int main(void) {
  char str[100] = TEXT;
  int str_length = 0;

  while (str[str_length] != '\0') {
    str_length += 1;
  }

  str[str_length - 1] = '.';

  /**
   *  макроопределение для тестирования
   *  (не убирать и должно идти непосредственно перед return 0)
   */
  __ASSERT_TESTS__
  return 0;
}
