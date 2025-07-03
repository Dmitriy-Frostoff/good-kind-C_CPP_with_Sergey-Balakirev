/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191301/step/7?unit=1204289}
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TOTAL 10
#define STR_SIZE 50
#define PRICE_TO_EXCLUDE 12300

int main(void) {
  char str[TOTAL][STR_SIZE] = {0};
  const char CHAR_DELIMETER_COLON[] = ":";
  const char CHAR_DELIMETER_SEMICOLON[] = ";";
  char res_str[TOTAL * STR_SIZE] = {0};
  int str_count = (int)sizeof(str) / (int)sizeof(*str);
  int chars_in_str_count = (int)sizeof(*str) / (int)sizeof(*str[0]);

  char *ptr_str_search = NULL;
  char *ptr_str_start = NULL;
  char *ptr_str_end = NULL;

  // get the input string
  // template >>>
  //  "<product name>: (int)<identifier>; (double)<price>; (double)<weight>"
  int count = 0;
  while (count < TOTAL && fgets(str[count], sizeof(str) - 1, stdin)) {
    // remove last '\n' from the 'str'
    char *ptr_n = strrchr(str[count], '\n');

    if (ptr_n != NULL) {
      *ptr_n = '\0';
    }

    count += 1;
  }

  for (int i = 0; i < str_count; i += 1) {
    // set the pointer to the str[i] begining
    ptr_str_start = str[i];

    // skip the empty strings
    if (*ptr_str_start == '\0') {
      continue;
    }

    // go to the first delimeter (':') >>> "<product name>: (int)<identifier>;
    ptr_str_search = strpbrk(str[i], CHAR_DELIMETER_COLON);

    // get the last char ptr of "<product name>:" => before ':'
    if (ptr_str_search != NULL) {
      ptr_str_end = ptr_str_search - 1;
    }

    // go to the second delimeter (';') >>> (int)<identifier>; (double)<price>
    ptr_str_search = strpbrk(ptr_str_search, CHAR_DELIMETER_SEMICOLON);

    // check that `(double)<price>;` is not 12300
    if (ptr_str_search != NULL) {
      double temp_value = 0;

      // set pointer to the next char after ';'
      ptr_str_search += 1;

      temp_value = atof(ptr_str_search);

      if (temp_value != PRICE_TO_EXCLUDE) {
        // +1 ? => '\0'
        int current_str_chunk_len = (int)(ptr_str_end - ptr_str_start + 1);
        int avaliable_space = (int)sizeof(res_str) -
                              ((int)strlen(res_str) + current_str_chunk_len);

        if (avaliable_space > 0) {
          strncat(res_str, ptr_str_start, current_str_chunk_len);
        }
        strcat(res_str, " ");
      } else {
        // set string for deleting
        *ptr_str_start = '\0';
      }
    }
  }

  // move strings with data to the begining of the str arr
  for (int i = 0, j = i + 1; j < str_count; i += 1, j += 1) {
    if (*str[i] == '\0' && *str[j] != '\0') {
      // copy all the data from the non - empty string
      sprintf(str[i], "%s", str[j]);
      // to zero all data at the empty string on the next step
      // pointer == first char == '\0'
      *str[j] = '\0';
    }
    // search for the non-empty string
    // (that pointer's value (first char) is not '\0')
    if (*str[i] == '\0' && *str[j] == '\0') {
      j += 1;
    }
  }

  // clean up data to '\0' in the strings
  //  (possible case: first char '\0' but next contain data)
  for (int i = str_count - 1; i >= 0; i -= 1) {
    if (*str[i] == '\0') {
      for (int j = 1; j < chars_in_str_count; j += 1) {
        // from the second char to the end
        if (*(str[i] + j) != '\0') {
          *(str[i] + j) = '\0';
        }
      }
    }
  }

  // reset pointers
  ptr_str_search = NULL;
  ptr_str_start = NULL;
  ptr_str_end = NULL;

  // remove last ' ' from the res_str
  ptr_str_search = strrchr(res_str, ' ');

  if (ptr_str_search != NULL) {
    // "... \0" => "...\0\0"
    *ptr_str_search = '\0';
    // reset pointer
    ptr_str_search = NULL;
  }

  puts(res_str);

  return 0;
}
