/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191306/step/5?unit=1204294}
 *
 */

#include "./config.h"
#include "./utils.h"

int main(void) {
  // for proper terminal handling of 'ru' chars
  setlocale(LC_ALL, ".UTF-8");

  char str[STR_SRC_SIZE] = {0};
  char str2[STR_DST_SIZE] = {0};

  // get the string from the input
  if (get_string_data(str, sizeof(str)) == 1) {
    return 1;
  }

  // remove '\n' from the end of string
  if (remove_str_last_n(str)) {
    return 1;
  }

  // copy str to str2
  copy_string(str2, sizeof(str2), str, check_latin_char);

  // print to the console str2
  puts(str2);

  return 0;
}
