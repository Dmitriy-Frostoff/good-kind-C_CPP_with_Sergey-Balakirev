/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191297/step/9?unit=1204285}
 *
 */

#include <stdio.h>

#define TEXT "best string!"
#define TEXT_FRAGMENT "The"
#define STR_ARR_LENGTH 50

int main(void) {
  char str[STR_ARR_LENGTH] = TEXT;
  char str_fragment[] = TEXT_FRAGMENT;
  char str_length = 0;
  char str_fragment_length = 0;

  /**
   *  @example
   *    "best string!" => str_length = 12 (indexes: 0-11),
   *    but actual => {"'b', 'e', 's', 't', ' ',
   *      's', 't', 'r', 'i', 'n', 'g', '!', \0"} => 13 (0-12)
   */
  while (str[str_length] != '\0') {
    str_length += 1;
  }

  // "best string!" and '\0' => 12 + 1
  str_length += 1;

  while (str_fragment[str_fragment_length] != '\0') {
    str_fragment_length += 1;
  }

  // "The" + ' ' => 3 + 1 => "The "
  str_fragment_length += 1;

  /**
   *  @example
   *   {'b', 'e', 's', 't', ' ', 's', 't', 'r', 'i', 'n', 'g', '!', '\0',
   *     0 x 37} (str_length = 13) and {'T', 'h', 'e', ' '}
   *     (str_fragment_length = 3 + 1) =>
   *   {'b', 'e', 's', 't', 'b', 'e', 's', 't', ' ', 's', 't', 'r', 'i', 'n',
   *    'g', '!', '\0', 0 x 33} index of '\0' == 16
   *     ((str_length + str_fragment_length) - 1)
   */
  for (char i = str_length + str_fragment_length - 1; i >= 0; i -= 1) {
    str[i] = str[i - str_fragment_length];
  }

  /**
   *  @example
   *    {'b', 'e', 's', 't', 'b', 'e', 's', 't', ' ', 's', 't', 'r', 'i', 'n',
   * 'g', '!', '\0'} and {'T', 'h', 'e'} and ' ' after it
   *    (str_fragment_length = 4) =>
   *    {'T', 'h', 'e', ' ', 'b', 'e', 's', 't', ' ', 's', 't', 'r', 'i', 'n',
   *      'g', '!', '\0'}
   */
  for (char i = 0; i <= str_fragment_length - 1; i += 1) {
    if (i == str_fragment_length - 1) {
      str[i] = ' ';
      continue;
    }
    str[i] = str_fragment[i];
  }

  /**
   *  макроопределение для тестирования
   *  (не убирать и должно идти непосредственно перед return 0)
   */
  __ASSERT_TESTS__
  return 0;
}
