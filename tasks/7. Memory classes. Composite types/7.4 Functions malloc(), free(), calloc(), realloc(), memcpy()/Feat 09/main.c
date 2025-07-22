/**
 *  The task description is at
 *  @link{https://stepik.org/lesson/1191313/step/11?unit=1204301}
 *
 */

#include "./config.h"
#include "./utils.h"

int main(void) {
  char str_1[STR_FIRST_SIZE] = {0};
  char str_2[STR_SECOND_SIZE] = {0};

  // get strings data from the INPUT:
  get_ln(str_1, sizeof(str_1));
  get_ln(str_2, sizeof(str_2));

  // merge strings
  char *ptr_merged_str = merge_string(str_1, str_2);

  if (ptr_merged_str == NULL) {
    puts("Error: 'merge_string()' function returned NULL");
    return 1;
  }

  puts(ptr_merged_str);

  // clean up
  free(ptr_merged_str);
  ptr_merged_str = NULL;

  return 0;
}
