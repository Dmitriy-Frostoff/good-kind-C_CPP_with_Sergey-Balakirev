/**
 *  The task description is at
 *  @link{https://stepik.org/lesson/1191313/step/7?unit=1204301}
 *
 */

#include "./config.h"
#include "./utils.h"

int main(void) {
  size_t count = 0;
  double digits[MAX_READ_NUM_QUANTITY] = {0};
  size_t arr_size = sizeof(digits) / sizeof(*digits);

  // fill @link{digits} with real numbers of @link{MAX_READ_NUM_QUANTITY} count
  count = get_real_nums(digits, arr_size, MAX_READ_NUM_QUANTITY);

  // allocate memory for @link{count} elems @type{double}
  double *ptr_d = (double *)allocate_clear_memory(count, sizeof(double));

  if (ptr_d == NULL) {
    puts("Error: impossible allocate memory for 'double *ptr_d'");
    return 1;
  }

  // copy @link{digits} nums to the @link{ptr_d} area
  memcpy(ptr_d, digits, count * sizeof(double));

  /*
   * макроопределение для тестирования (не убирать)
   */
  __ASSERT_TESTS__;

  // free allocated memory
  free(ptr_d);
  // wipe pointer
  ptr_d = NULL;

  return 0;
}
