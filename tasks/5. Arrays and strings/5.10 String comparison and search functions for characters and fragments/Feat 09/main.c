/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191300/step/11?unit=1204288}
 *
 */

#include <stdio.h>
#include <string.h>

#define STR_MAX_SIZE 100

int main(void) {
  char str[STR_MAX_SIZE] = {0};
  char *ptr_n = NULL;
  char *ptr_search_char_left = NULL;
  char *ptr_search_char_right = NULL;
  int str_char_code = -1;
  int str_len = 0;
  int res_binary = 0;

  // valid ASCII codes of chars
  const char CHAR_CODE_HYPHEN = 45;
  const char CHAR_CODE_DOT = 46;
  const char CHAR_CODE_NUM_ZERO = 48;
  const char CHAR_CODE_NUM_NINE = 57;
  const char CHAR_CODE_AT = 64;
  const char CHAR_CODE_A = 65;
  const char CHAR_CODE_Z = 90;
  const char CHAR_CODE_UNDERSCORE = 95;
  const char CHAR_CODE_A_LOW = 97;
  const char CHAR_CODE_Z_LOW = 122;

  if (fgets(str, sizeof(str) - 1, stdin) == NULL) {
    puts("empty input. Type correct email");
    return 0;
  };

  // remove last '\n' after 'fgets()' func execution
  ptr_n = strrchr(str, '\n');

  if (ptr_n != NULL) {
    *ptr_n = '\0';
  }

  // check that the first char in the 'str' is a letter [a-zA-Z]
  ptr_search_char_left = str;
  // 97 => 'a', 122 => 'z'
  str_char_code = (int)(*ptr_search_char_left);

  //  not a letter from [a-zA-Z] ? => 0
  if (!((str_char_code >= CHAR_CODE_A && str_char_code <= CHAR_CODE_Z) ||
        (str_char_code >= CHAR_CODE_A_LOW &&
         str_char_code <= CHAR_CODE_Z_LOW))) {
    res_binary = 0;
    printf("%d\n", res_binary);
    return 0;
  }

  // reset pointers
  ptr_search_char_left = NULL;
  // reset value
  str_char_code = -1;

  // check that the only '@' is in the 'str' and not the first
  ptr_search_char_left = strchr(str, '@');
  // ptr_search_char_left + 1 => search from the next char
  ptr_search_char_right = strchr(ptr_search_char_left + 1, '@');

  if (ptr_search_char_left == NULL || ptr_search_char_left == str ||
      ptr_search_char_right != NULL) {
    res_binary = 0;
    printf("%d\n", res_binary);
    return 0;
  }

  // reset pointers
  ptr_search_char_left = NULL;
  ptr_search_char_right = NULL;

  // check that '.' char is in the 'str' and passes not write after '@'
  ptr_search_char_left = strchr(str, '@');
  ptr_search_char_right = strchr(ptr_search_char_left + 1, '.');

  if (ptr_search_char_right == NULL ||
      ptr_search_char_right - ptr_search_char_left < 2) {
    res_binary = 0;
    printf("%d\n", res_binary);
    return 0;
  }

  // reset pointers
  ptr_search_char_left = NULL;
  ptr_search_char_right = NULL;

  // check that multiple '.' chars are absent after '@'
  ptr_search_char_left = strchr(str, '@');
  ptr_search_char_right = strstr(ptr_search_char_left + 1, "..");

  if (ptr_search_char_right != NULL) {
    res_binary = 0;
    printf("%d\n", res_binary);
    return 0;
  }

  // reset pointers
  ptr_search_char_left = NULL;
  ptr_search_char_right = NULL;

  // check that '.' char is absent at the end of 'str'
  str_len = (int)strlen(str);
  str_char_code = (int)str[str_len - 1];

  if (str_char_code == CHAR_CODE_DOT) {
    res_binary = 0;
    printf("%d\n", res_binary);
    return 0;
  }

  // reset value
  str_char_code = -1;

  // check that 'str' contains only a-z, A-Z, 0-9, '.', '_', '-' and '@' chars
  for (int i = 0; i < str_len; i += 1) {
    str_char_code = (int)str[i];

    // check for incorrect chars
    // not a valid ASCII codes of chars ? => 0
    if (!((str_char_code == CHAR_CODE_HYPHEN) ||
          (str_char_code == CHAR_CODE_DOT) ||
          (str_char_code >= CHAR_CODE_NUM_ZERO &&
           str_char_code <= CHAR_CODE_NUM_NINE) ||
          (str_char_code == CHAR_CODE_AT) ||
          (str_char_code >= CHAR_CODE_A && str_char_code <= CHAR_CODE_Z) ||
          (str_char_code == CHAR_CODE_UNDERSCORE) ||
          (str_char_code >= CHAR_CODE_A_LOW &&
           str_char_code <= CHAR_CODE_Z_LOW))) {
      res_binary = 0;
      printf("%d\n", res_binary);
      return 0;
    }
  }

  res_binary = 1;
  printf("%d\n", res_binary);

  return 0;
}
