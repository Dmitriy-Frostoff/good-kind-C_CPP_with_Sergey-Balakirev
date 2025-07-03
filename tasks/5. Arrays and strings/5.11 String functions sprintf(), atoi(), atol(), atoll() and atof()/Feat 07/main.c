/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191301/step/9?unit=1204289}
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_SIZE 250
#define MAX_MARKS_QUANTITY 20

int main(void) {
  char str[STR_SIZE] = {0};
  char res_str[STR_SIZE] = {0};
  int str_size = (int)sizeof(str);
  int res_str_size = (int)sizeof(res_str);
  int str_len = 0;
  int res_str_len = 0;

  const char CHAR_DELIMETER_COMMA[] = ",";
  const char CHAR_DELIMETER_COLON[] = ":";
  const char CHAR_DELIMETER_SPACE[] = " ";
  int marks_count = 0;

  char *ptr_search = NULL;

  // get the input string
  // template >>>
  //  "<surname> (int)<mark> (int)<mark> (int)<mark> ...(int)<mark>"
  if (fgets(str, sizeof(str) - 1, stdin) == NULL) {
    puts("expected string like: '<surname> (int)<mark> (int)<mark> "
         "(int)<mark> ...(int)<mark>'");
    return 0;
  }

  // remove '\n' from the 'str'
  ptr_search = strrchr(str, '\n');
  if (ptr_search != NULL) {
    *ptr_search = '\0';
  }
  ptr_search = NULL;

  // get actual 'str' length
  str_len = (int)strlen(str);

  // create res_str like
  //  "<surname>: (int)<mark>, (int)<mark>, (int)<mark>,...(int)<mark>"
  for (int i = 0; i < str_size; i += 1) {
    // check the marks quantity
    if (marks_count >= MAX_MARKS_QUANTITY) {
      break;
    }

    // " " ? => continue, atoi will skip " "
    // till the first char will be found or '\0'
    if (str[i] == *CHAR_DELIMETER_SPACE) {
      continue;
    }

    // 'atoi()' expect the address => &str[i]
    int current_number = atoi(&str[i]);

    res_str_len = (int)strlen(res_str);

    // char in the 'str' is not a ":" or "," ? =>
    //  copy it to the 'res_str' and add ":"
    if (current_number == 0 && str[i] != *CHAR_DELIMETER_COLON &&
        str[i] != *CHAR_DELIMETER_COMMA) {
      if (res_str_size - (res_str_len + 1) > 0) {
        strncat(res_str, &str[i], 1);
      }

      // next char in the 'str' is " " ? => add ": " to the 'res_str'
      if (str[i + 1] == *CHAR_DELIMETER_SPACE) {
        res_str_len = (int)strlen(res_str);

        // ...+2 ? => adding two chars
        if (res_str_size - (res_str_len + 2) > 0) {
          strncat(res_str, CHAR_DELIMETER_COLON, 1);
          strncat(res_str, CHAR_DELIMETER_SPACE, 1);
        }
      }
    }

    // char in 'str' is int => copy char and add ", " after it to the 'res_str'
    if (current_number != 0) {
      marks_count += 1;

      if (res_str_size - (res_str_len + 1) > 0) {
        strncat(res_str, &str[i], 1);
      }

      // not a last int in the 'str' ? => add "," and " " to the 'res_str'
      if (i != str_len - 1) {
        res_str_len = (int)strlen(res_str);

        if (res_str_size - (res_str_len + 2) > 0) {
          strncat(res_str, CHAR_DELIMETER_COMMA, 1);
          strncat(res_str, CHAR_DELIMETER_SPACE, 1);
        }
      }
    }
  }

  puts(res_str);

  return 0;
}
