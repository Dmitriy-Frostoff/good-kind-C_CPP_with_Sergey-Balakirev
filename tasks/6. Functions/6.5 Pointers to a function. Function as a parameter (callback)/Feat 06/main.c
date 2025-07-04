/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191306/step/8?unit=1204294}
 *
 */

#include "./config.h"
#include "./utils.h"

int main(void) {
  char str[STR_SIZE] = {0};
  size_t str_len = 0;

  // get the string from the input
  if (get_string_data(str, sizeof(str)) == 1) {
    return 1;
  }

  // remove '\n' from the end of string
  if (remove_str_last_n(str)) {
    return 1;
  }

  // get actual @link{str} length
  str_len = strlen(str);

  sort_string(str, str_len, match_ab);

  // print the sorted @link{str}
  puts(str);

  return 0;
}
