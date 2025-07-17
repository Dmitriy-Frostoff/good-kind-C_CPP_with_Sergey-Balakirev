#include "./utils.h"

/**
 *  @brief Get the divisors of @link{num} (including 1 and @link{num} itself)
 *  @note ! Impure function! Mutates the original @link{arr} !
 *
 *  @param {unsigned int} num - number to find divisors
 *  @param {unsigned int []} arr - array to fill with @link{num} divisors
 *  @param {size_t} arr_size - size of @link{arr}
 *
 *  @return {size_t} - quantity of added divisors of @link{num}
 *
 *  @example
 *    unsigned int num = 875;
 *    unsigned int arr[20] = {0};
 *    size_t arr_size - 20;
 *    get_divisors_of_num(num, arr, arr_size) => 8
 *      arr{1, 5, 7, 25, 35, 125, 175, 875}
 */
size_t get_divisors_of_num(unsigned int num, unsigned int arr[],
                           size_t arr_size) {
  size_t arr_index = 0;

  // i = 1 ? => no division by 0
  for (unsigned int i = 1; i <= (unsigned int)(ceil(num / 2)); i += 1) {
    if (num % i == 0) {
      arr[arr_index] = i;
      arr_index += 1;
    }
  }

  // add the @link{num} itself
  arr[arr_index] = num;
  arr_index += 1;

  // @note divisors quantity is arr_index + 1 (index starts from 0)
  // e.g. num = 7, arr{1, 7} => arr_index = 1, nums quantity = 2 (arr_index + 1)
  return arr_index;
}
