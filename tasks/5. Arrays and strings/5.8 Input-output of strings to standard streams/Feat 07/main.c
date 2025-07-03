/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191298/step/9?unit=1204286}
 *
 */

#include <stdio.h>

#define STR_MAX_LENGTH 100

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
  char str[STR_MAX_LENGTH];
  int character_count = 0;
  int words_counter = 0;

  fgets(str, sizeof(str), stdin);
  strip_string(str, sizeof(str));

  // "letter" => character_count = 6
  //  (indexOf l = 0, character_count = 1;
  //  indexOf r = 5, character_count = 6,
  //  exclude indexOf '\0' = 6; 6 total)
  while (str[character_count] != '\0') {
    character_count += 1;
  }

  for (int i = 0, j = i + 1; i < character_count; i += 1, j += 1) {
    if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && str[i] != '\0') {
      if (str[j] != ' ' && str[j] != '\t' && str[j] != '\n' && str[j] != '\0') {
        continue;
      }
      words_counter += 1;
    }
  }

  printf("%d", words_counter);

  return 0;
}
