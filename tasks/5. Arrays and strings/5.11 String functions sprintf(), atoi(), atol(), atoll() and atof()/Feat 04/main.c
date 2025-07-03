/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191301/step/6?unit=1204289}
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_SIZE 200
#define CSV_ARR_SIZE 50

int main(void) {
  char str[STR_SIZE] = {0};
  const char CHAR_DELIMETER[] = ":;";
  int str_len = 0;
  double csv[CSV_ARR_SIZE] = {0.0};

  char *ptr_n = NULL;
  char *ptr_str = NULL;
  double *ptr_csv_arr = NULL;

  // get the input string
  if (fgets(str, sizeof(str) - 1, stdin) == NULL) {
    puts("empty input. Print something like this: 'data: real_num; real_num; "
         "real_num'");
    return 0;
  }

  // remove last '\n' from the 'str'
  ptr_n = strrchr(str, '\n');

  if (ptr_n != NULL) {
    *ptr_n = '\0';
  }

  // fill the `csv` with (double)number from the `str`
  // 'data: 42.24; 24.42;16.42' and delimeter {:;} => {42.24, 24.42, 16.42}
  str_len = (int)strlen(str);
  ptr_csv_arr = csv;

  for (int i = 0; i < str_len; i += 1) {
    if (i == 0) {
      // 'data: 42.24; 24.42;16.42' and delimeter {:;} => ': 42.24; 24.42;16.42'
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

    // ': 42.24; 24.42;16.42' => 0
    // ' 42.24; 24.42;16.42' => 42.24
    // '42.24; 24.42;16.42' => 42.24
    double temp_num = atof(ptr_str);

    if (temp_num == 0) {
      continue;
    }

    *ptr_csv_arr = temp_num;
    ptr_csv_arr += 1;
  }

  /**
   * макроопределение для тестирования
   * (не убирать и должно идти непосредственно перед return 0)
   */
  __ASSERT_TESTS__
  return 0;
}
