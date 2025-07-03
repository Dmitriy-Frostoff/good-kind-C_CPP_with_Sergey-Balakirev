/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191299/step/6?unit=1204287}
 *
 */

#include <stdio.h>
#include <string.h>

#define MAX_STRING_LENGTH 100

// !!! IMPURE FUNCTION!!!
/**
 * @brief
 *   Remove '\n' symbol from the end of the string
 *
 * @example
 *   "letter" i.e. {'l', 'e', 't', 't', 'e', 'r', '\n', '\0'} =>
 *     {'l', 'e', 't', 't', 'e', 'r', '\0'}
 */
void strip_string(char *str, int max_len) {
  int count = 0;

  while (*str != '\0' && count < max_len) {
    str += 1;
    count += 1;
  };

  if (count > 1) {
    // move pointer one byte back
    str -= 1;

    if (*str == '\n') {
      *str = '\0';
    }
  }
}

int main(void) {
  char str[MAX_STRING_LENGTH];
  char res_str[MAX_STRING_LENGTH] = "I love language C ";
  int res_str_length;
  int sizeof_res_str = (int)sizeof(res_str);

  fgets(str, sizeof_res_str, stdin);
  strip_string(str, sizeof_res_str);

  res_str_length = (int)strlen(res_str);

  // res_str_length + str_length + 1 => ...+1 => for '\0'
  strncat(res_str, str, sizeof_res_str - (res_str_length + 1));

  // add for sure end of the string after last character
  res_str[(int)strlen(res_str)] = '\0';

  puts(res_str);

  return 0;
}
