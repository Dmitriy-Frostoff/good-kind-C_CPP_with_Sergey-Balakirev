/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191300/step/4?unit=1204288}
 *
 */

#include <stdio.h>
#include <string.h>

#define STR_LENGTH 100

int main(void) {
  char str[STR_LENGTH] = {0};
  char *ptr_last_str_brk = NULL;

  fgets(str, sizeof(str) - 1, stdin);

  // get the adress of the last '\n' char
  ptr_last_str_brk = strrchr(str, '\n');

  // ...\n\0 => ...\0
  if (ptr_last_str_brk != NULL) {
    *ptr_last_str_brk = '\0';
  }

  printf("[%s]", str);

  return 0;
}
