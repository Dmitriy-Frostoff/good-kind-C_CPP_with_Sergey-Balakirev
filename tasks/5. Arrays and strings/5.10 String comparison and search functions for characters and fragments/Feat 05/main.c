/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191300/step/7?unit=1204288}
 *
 */

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define STR_SIZE 100

int main(void) {
  char str[STR_SIZE] = {0};
  char res_str[STR_SIZE] = {0};
  int res_str_size = (int)sizeof(res_str);
  int str_len = 0;
  bool isDelimeterOnTop = false;

  const char *PTR_STR = str;
  const char WORD_DELIMETER[] = "-";

  // get the 'str' from the user input
  fgets(str, sizeof(str) - 1, stdin);

  // replace '\n' with '\0'
  char *ptr_n = strrchr(str, '\n');

  if (ptr_n != NULL) {
    *ptr_n = '\0';
  }

  str_len = (int)strlen(str);

  // empty data ? return
  if (!str_len) {
    puts("empty input data");
    return 0;
  }

  // copy chars from the 'str' to the 'res_str'
  // without WORD_DELIMETER duplication
  //
  // strncat(res_str, (PTR_STR + i), 1) => 1 ? => to copy just current char
  // 'strcat' will copy the hole 'str' via pointer (till the '\0' char met)
  //
  // strncmp((PTR_STR + i), WORD_DELIMETER, 1) 1 ? => to compare just current
  // char but not the hole strings through over the lengths
  //
  // -cpp---znacheniya-- => -cpp-znacheniya-
  for (int i = 0, j = i + 1; i < str_len; i += 1, j += 1) {
    int res_of_strncmp = strncmp((PTR_STR + i), WORD_DELIMETER, 1);

    if ((res_of_strncmp == 0 && !isDelimeterOnTop) || res_of_strncmp != 0) {
      // WORD_DELIMETER ? => true
      if (res_of_strncmp == 0) {
        isDelimeterOnTop = true;
      }

      // another char ? => false
      if (res_of_strncmp != 0) {
        isDelimeterOnTop = false;
      }

      // check for free space at 'res_str' and add current char to the res_str
      if (res_str_size - 1 - (int)strlen(res_str) > 0) {
        strncat(res_str, (PTR_STR + i), 1);
      }
    }
  }

  puts(res_str);

  return 0;
}
