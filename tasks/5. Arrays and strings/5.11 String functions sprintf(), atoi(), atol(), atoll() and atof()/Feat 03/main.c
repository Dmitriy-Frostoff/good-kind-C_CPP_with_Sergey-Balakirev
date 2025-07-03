/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191301/step/5?unit=1204289}
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_SIZE 100

int main(void) {
  char str[STR_SIZE] = {0};
  int h = -1;
  int w = -1;
  int d = -1;
  const char CHAR_DELIMETER[] = ":x";
  int str_len = 0;

  char *ptr_n = NULL;
  char *ptr_str = NULL;

  // get the input string
  if (fgets(str, sizeof(str) - 1, stdin) == NULL) {
    puts("empty input. Print something like this: 'data: val x val x val'");
    return 0;
  }

  // remove last '\n' from the 'str'
  ptr_n = strrchr(str, '\n');

  if (ptr_n != NULL) {
    *ptr_n = '\0';
  }

  // check that `str` includes ':' and 'x' after it
  if (strchr(str, CHAR_DELIMETER[0]) == NULL ||
      strrchr(str, CHAR_DELIMETER[1]) == NULL) {
    puts("Incorrect input. Expected string like this: 'data: integer x "
         "integer x "
         "integer'");

    return 0;
  }

  // extracting nums from the 'str' to the variables: h, w, d
  // 'data: val_1 x val_2 x val_3' => h = val1, w = val_2, d = val_3,
  str_len = (int)strlen(str);

  for (int i = 0; i < str_len; i += 1) {
    if (i == 0) {
      // 'data: 42 x 24 x 16' and delimeter {:x} => ': 42 x 24 x 16'
      ptr_str = strpbrk(str, CHAR_DELIMETER);

      if (ptr_str == NULL) {
        break;
      }

      ptr_str += 1;
    } else {
      // got the next delimeter
      ptr_str = strpbrk(ptr_str, CHAR_DELIMETER);

      if (ptr_str == NULL) {
        break;
      }

      // set pointer right after the delimeter
      ptr_str += 1;
    }

    // ': 42 x 24 x 16' => 0
    // ' 42 x 24 x 16' => 42
    // '42 x 24 x 16' => 42
    int temp_num = atoi(ptr_str);

    if (temp_num == 0) {
      continue;
    }

    // not set ? => assign value
    if (h == -1) {
      h = temp_num;
      continue;
    }

    if (w == -1 && h != -1) {
      w = temp_num;
      continue;
    }

    if (d == -1 && w != -1 && h != -1) {
      d = temp_num;
      // all the variables are set => break
      break;
    }
  }

  if ((h == -1 || !h) || (w == -1 || !w) || (d == -1 || !d)) {
    puts("Incorrect input. Expected string like this: 'data: integer x "
         "integer x "
         "integer'");
    return 0;
  }

  /**
   * макроопределение для тестирования
   * (не убирать и должно идти непосредственно перед return 0)
   */
  __ASSERT_TESTS__
  return 0;
}
