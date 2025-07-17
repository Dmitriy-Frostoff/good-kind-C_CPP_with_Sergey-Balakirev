/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191311/step/7?unit=1204299}
 *
 */

#include "./config.h"
#include "./utils.h"

int main(void) {
  unsigned int n;
  unsigned int divisors_arr[DIVISORS_ARR_SIZE] = {0};
  size_t divisors_arr_size = sizeof(divisors_arr) / sizeof(*divisors_arr);
  size_t nums_count = 0;

  // get natural number from the INPUT:
  if (get_natural_num(&n) != 0) {
    return 1;
  }

  // get divisors of @link{n} to @link{divisors_arr}
  nums_count = get_divisors_of_num(n, divisors_arr, divisors_arr_size);

  // print divisors
  print_integers(divisors_arr, divisors_arr_size, nums_count);

  return 0;
}
