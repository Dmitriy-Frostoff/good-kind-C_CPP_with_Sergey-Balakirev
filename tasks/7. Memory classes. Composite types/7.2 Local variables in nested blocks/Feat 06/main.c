/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191311/step/8?unit=1204299}
 *
 */

#include "./config.h"
#include "./utils.h"

int main(void) {
  unsigned int n;
  unsigned int prime_factors_arr[PRIME_FACTORS_ARR_SIZE] = {0};
  size_t prime_factors_arr_size =
      sizeof(prime_factors_arr) / sizeof(*prime_factors_arr);
  size_t nums_count = 0;

  // get natural number from the INPUT:
  if (get_natural_num(&n) != 0) {
    return 1;
  }

  // get prfme_vactors of @link{n} to @link{prime_factors_arr}
  nums_count = get_prime_factors_of_num(
      n, prime_factors_arr, prime_factors_arr_size, get_eratosthen_sieve);

  // print prfme_vactors
  print_integers(prime_factors_arr, prime_factors_arr_size, nums_count);

  return 0;
}
