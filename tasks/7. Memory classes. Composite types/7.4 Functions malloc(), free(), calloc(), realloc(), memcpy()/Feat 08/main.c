/**
 *  The task description is at
 *  @link{https://stepik.org/lesson/1191313/step/10?unit=1204301}
 *
 */

#include "./config.h"
#include "./utils.h"

int main(void) {
  short *ptr_d = (short *)calloc(TOTAL, sizeof(short));
  size_t len = TOTAL;
  int count = 0;
  short fill_num = -1;

  if (ptr_d == NULL) {
    puts("Error: impossible to allocate memory for 'short *ptr_d'");
    return 1;
  }

  // fill @link{ptr_d} with integers of @link{TOTAL} count
  count = get_int_nums(ptr_d, len, TOTAL);

  // check the allocated memory and double size if needed
  ptr_d = (short *)expand_array(ptr_d, &len, fill_num);

  // print the updated @link{ptr_d} value
  print_integers(ptr_d, len, len);

  // clean up
  free(ptr_d);
  ptr_d = NULL;

  return 0;
}
