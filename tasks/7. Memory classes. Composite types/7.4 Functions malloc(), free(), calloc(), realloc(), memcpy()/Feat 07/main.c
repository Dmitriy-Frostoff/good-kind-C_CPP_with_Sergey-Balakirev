/**
 *  The task description is at
 *  @link{https://stepik.org/lesson/1191313/step/9?unit=1204301}
 *
 */

#include "./config.h"
#include "./utils.h"

int main(void) {
  size_t count = 0;
  int lengths[MAX_READ_NUM_QUANTITY] = {0};
  size_t arr_size = sizeof(lengths) / sizeof(*lengths);

  // fill @link{lengths} with real numbers of @link{MAX_READ_NUM_QUANTITY} count
  count = get_int_nums(lengths, arr_size, MAX_READ_NUM_QUANTITY);

  // allocate memory for @link{count} elems @type{int}
  int *ptr_lens = (int *)allocate_clear_memory(count, sizeof(int));

  if (ptr_lens == NULL) {
    puts("Error: impossible allocate memory for 'int *ptr_lens'");
    return 1;
  }

  // copy @link{lengths} nums to the @link{ptr_lens} area
  memcpy(ptr_lens, lengths, count * sizeof(int));

  // print @link{MAX_READ_NUM_QUANTITY} integers to the console
  print_integers(lengths, arr_size, MAX_READ_NUM_QUANTITY);

  /*
   * макроопределение для тестирования (не убирать)
   */
  __ASSERT_TESTS__;

  // free allocated memory
  free(ptr_lens);
  // wipe pointer
  ptr_lens = NULL;

  return 0;
}
