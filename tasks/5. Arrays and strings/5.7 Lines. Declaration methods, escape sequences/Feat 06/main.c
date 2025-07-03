/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191297/step/8?unit=1204285}
 *
 */

#include <stdio.h>

#define TEXT "Best string!"

int main(void) {
  char str[100] = TEXT;
  char str_length = 0;

  while (str[str_length] != '\0') {
    str_length += 1;
  }

  /**
   *  @example
   *    "Best string!" => "Bet tring!"
   *    "Bessst sSsstring!" => "Bet tring!"
   */
  for (char i = 0; i <= str_length; i += 1) {
    if (str[i] == 's' || str[i] == 'S') {
      for (char j = i; j <= str_length; j += 1) {
        str[j] = str[j + 1];
        // to prevent skipping letter multiplication
        // e.g."Bessst" => "Best" 's'[index 3] were skipped
        if (str[j + 1] == 's' || str[j + 1] == 'S') {
          i -= 1;
        }
      }
    }
  }

  /**
   *  макроопределение для тестирования
   *  (не убирать и должно идти непосредственно перед return 0)
   */
  __ASSERT_TESTS__
  return 0;
}
