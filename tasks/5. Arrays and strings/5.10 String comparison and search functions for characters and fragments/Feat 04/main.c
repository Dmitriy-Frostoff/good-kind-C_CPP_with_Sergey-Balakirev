/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191300/step/6?unit=1204288}
 *
 */

#include <stdio.h>
#include <string.h>

#define STR_SIZE 100

int main(void) {
  char str[STR_SIZE] = {0};
  const char LITERAL_TEMPLATE[] = "-+-";
  const int LITERAL_TEMPLATE_LENGTH = strlen(LITERAL_TEMPLATE);
  int hyphen_count = 0;
  int str_chars_count = 0;

  char *ptr_to_hyphen = NULL;
  char *ptr_last_char = NULL;

  fgets(str, sizeof(str) - 1, stdin);

  ptr_to_hyphen = strchr(str, '-');
  // ...\n\0 => ptr_last_char = \0
  ptr_last_char = &str[(int)strlen(str)];

  while (ptr_to_hyphen != NULL) {
    hyphen_count += 1;
    ptr_to_hyphen += 1;
    ptr_to_hyphen = strchr(ptr_to_hyphen, '-');
  }

  // get max str characters count
  str_chars_count = (int)strlen(str) + hyphen_count * LITERAL_TEMPLATE_LENGTH;

  if (!hyphen_count) {
    puts(str);
    return 0;
  }

  if (str_chars_count > sizeof(str)) {
    printf("increase str[] size. Required additional %d bytes",
           str_chars_count - (int)sizeof(str));
    return 0;
  }

  // strrchr won't help in the cycle! It's search from the left to the right
  // same as 'strchr' and returns just last match or NULL
  ptr_to_hyphen = strchr(str, '-');

  while (ptr_to_hyphen != NULL && ptr_last_char != NULL) {
    for (char *j = ptr_last_char; j > ptr_to_hyphen; j -= 1) {
      // copy chars to the right
      // LITERAL_TEMPLATE_LENGTH - 1 => 3 - 1 => first char of "-+-" will be
      // just replaced
      *(j + LITERAL_TEMPLATE_LENGTH - 1) = *j;
    }

    // copy LITERAL_TEMPLATE (without last char '/0') to the ptr_to_hyphen
    // address
    // LITERAL_TEMPLATE_LENGTH for '-+-' = 3 ('/0' is not counted)
    strncpy(ptr_to_hyphen, LITERAL_TEMPLATE, LITERAL_TEMPLATE_LENGTH);

    // move ptr to the next address to search
    ptr_to_hyphen += LITERAL_TEMPLATE_LENGTH;
    ptr_to_hyphen = strchr(ptr_to_hyphen, '-');

    // update ptr_last_char
    ptr_last_char = &str[(int)strlen(str)];
  }

  puts(str);

  return 0;
}
