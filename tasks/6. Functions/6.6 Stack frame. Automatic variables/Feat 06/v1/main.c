/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191307/step/8?unit=1204295}
 *
 */

#include "./config.h"
#include "./utils.h"

int main(void) {
  char str[STR_SIZE] = {0};
  char str2[STR_TEMPLATE_SIZE] = ".,-!?";

  // get the string from the input
  if (get_string_data(str, sizeof(str)) == 1) {
    return 1;
  }

  // remove '\n' from the end of string
  if (remove_str_last_n(str)) {
    return 1;
  }

  // mutate the @link{str} => remove all @link{str2} chars
  strip_str(str, str2);

  // print to the console str
  puts(str);

  return 0;
}
