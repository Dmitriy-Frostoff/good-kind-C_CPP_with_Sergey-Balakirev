#include "./utils.h"

/**
 *  @brief Sum the even numbers from the @link{arr}
 *
 *  @param {int[]} arr - array of integers
 *  @param {size_t} len_arr - array length
 *  @param {int (*)(const int num)} check_callback - callback for checking the
 *   @link{arr} num
 *
 *  @return {int} - sum of the even numbers
 *
 *  @example
 *    const arr[20] = {1, 2, 3, 4, 5}
 *    @see{is_even}
 *      sum_ar(arr, 20, is_even) => 6
 *        2 + 4 => 6
 */
int sum_ar(const int arr[], size_t len_arr, int (*check_callback)(const int)) {
  int sum = 0;

  for (size_t i = 0; i < len_arr; i += 1) {
    if (check_callback(arr[i]) == 1) {
      sum += arr[i];
    }
  }

  return sum;
}
