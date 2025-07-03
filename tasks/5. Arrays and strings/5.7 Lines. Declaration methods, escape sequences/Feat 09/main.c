/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191297/step/11?unit=1204285}
 *
 */

#include <stddef.h>
#include <stdio.h>

#define STR_LENGTH 50

int main(void) {
  char str[STR_LENGTH] = "Best   language  \"C\"";
  size_t str_length = 0;
  char str_length_reduce_count = 0;
  char char_after_space_index = -1;

  while (str[str_length] != '\0') {
    str_length += 1;
  }

  /**
   * @example
   *   "Best" => str_length = 4
   *   index of t = 3
   *
   *   "Best   language  \"C\"" =>
   *    "Best\nlanguage\n\"C\""
   *    (replace all spaces to '\n')
   */
  for (size_t i = 0; i < str_length; i += 1) {
    if (str[i] == ' ') {
      str[i] = '\n';

      /**
       * @example
       *   "Best   language" i = 4 (indexof ' ' just after 't'),
       *     indexof 't' = 3, indexof 'l' = 7 =>
       *     char_after_space_index = 7
       */
      for (size_t j = i + 1; j < str_length; j += 1) {
        //         *
        // "Best   l" => indexof 'l';
        //        *
        // "Best   " => indexof last ' ' i.e str_length - 1;
        if (str[j] != ' ' || str[j] == str_length - 1) {
          char_after_space_index = j;

          /**
           * @example
           *  "Best   l" str_length = 8 =>
           *    i = index of first ' ' just after 't'= 4,
           *    index of 'l' = 7,
           *    after 't' nest symbol '\n'
           *    "Best\nl"=> 7 - (4 + 1)
           */
          str_length_reduce_count = char_after_space_index - (i + 1);
          break;
        }
      }

      //      *
      // "Best l" => do nothing (will be => "Best\nl");
      /**
       * @example
       *   "Best   language" =>
       *    "Best language"
       *    (move every char to the left till first space ' ',
       *     i = 4 (it's a first ' '), i + 1 is a next ' ')
       */
      if (char_after_space_index - i > 1) {
        for (size_t k = i + 1; k < str_length; k += 1) {
          str[k] = str[char_after_space_index];

          if (char_after_space_index != str_length - 1) {
            char_after_space_index += 1;
          }
        }
      }

      // reset value
      char_after_space_index = -1;

      str_length -= str_length_reduce_count;

      // reset value
      str_length_reduce_count = 0;
    }
  }

  /**
   * @note
   *  remove characters right after new string!
   *  They've stayed after copiing characters like str[i] = str[i + 1]
   * @example
   *  str[50] = {'B', 'e', 's', 't', '\n', 'l', 'a', 'n', 'g', 'u', 'a', 'g',
   *    'e', '\n', '"', 'C', '"', ' ', '\"', 'C', '\"', '\0', 0 x 29} =>
   *    {'B', 'e', 's', 't', '\n', 'l', 'a', 'n', 'g', 'u', 'a', 'g', 'e', '\n',
   *      '"', 'C', '"', '\0', 0 x 32}
   */
  for (size_t i = str_length; i < STR_LENGTH; i += 1) {
    str[i] = 0;
  }

  /**
   * макроопределение для тестирования
   * (не убирать и должно идти непосредственно перед return 0)
   */
  __ASSERT_TESTS__
  return 0;
}
