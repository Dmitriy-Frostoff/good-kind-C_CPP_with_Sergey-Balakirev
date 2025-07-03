/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191298/step/8?unit=1204286}
 *
 */

#include <stdbool.h>
#include <stdio.h>

#define STR_LENGTH 100

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
  char str[STR_LENGTH];
  int character_count = 0;
  int str_last_character = 0;
  bool isELetterMet = false;

  fgets(str, sizeof(str), stdin);
  strip_string(str, sizeof(str));

  // "letter" => character_count = 6
  //  (indexOf l = 0, character_count = 1;
  //  indexOf r = 5, character_count = 6,
  //  exclude indexOf '\0' = 6; 6 total)
  while (str[character_count] != '\0') {
    character_count += 1;
  }

  str_last_character = character_count;

  // get actual end of string
  for (int i = 0; i < character_count; i += 1) {
    if (str[i] == 'e') {
      str_last_character -= 1;
    }
  }

  for (int i = 0, j = i + 1; i < character_count; i += 1, j += 1) {
    // 'e' character ? move letters to the left
    if (str[i] == 'e') {
      isELetterMet = true;
      str[i] = str[j];

      // check value after replacement above
      if (str[i] == 'e') {
        // prevent 'e' after 'e' check skipping, 'j' will be next after current
        i -= 1;
      }

      continue;
    }

    if (isELetterMet) {
      str[i] = str[j];

      // check value after replacement above
      if (str[i] == 'e') {
        // prevent 'e' after 'e' check skipping, 'j' will be next after current
        i -= 1;
      }
    }
  }

  if (str_last_character >= 0 && str_last_character <= STR_LENGTH) {
    str[str_last_character] = '\0';
  }

  // clear outdated characters
  for (int i = str_last_character + 1; i < STR_LENGTH; i += 1) {
    str[i] = 0;
  }

  puts(str);

  return 0;
}
