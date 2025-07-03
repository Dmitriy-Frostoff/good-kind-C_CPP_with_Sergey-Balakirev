/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191300/step/5?unit=1204288}
 *
 */

#include <stdio.h>
#include <string.h>

#define STR_LENGTH 100

int main(void) {
  char str[STR_LENGTH] = {0};
  int count_literal_is = 0;

  // get the input string
  fgets(str, sizeof(str) - 1, stdin);

  // get the pointer address of the substring "is"
  char *ptr_literal_is = strstr(str, "is");

  while (ptr_literal_is != NULL) {
    count_literal_is += 1;
    ptr_literal_is += 1;
    ptr_literal_is = strstr(ptr_literal_is, "is");
  }

  printf("%d\n", count_literal_is);

  return 0;
}
