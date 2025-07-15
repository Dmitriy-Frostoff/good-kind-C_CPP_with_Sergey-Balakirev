#include "./utils.h"

/**
 *  @brief Count mean value of the @link{ar} for integers, that pass through the
 *  @callback{check_callback}
 *
 *  @param {const int []} ar - array of integers to check
 *  @param {size_t} len_ar - size of @link{ar}
 *  @param {int (*)(int)} check_callback - callback to check every @link{ar} num
 *
 *  @return {double} - counted mean value
 *
 *  @example
 *    const int ar[20] = {-5, -3, -2, 0, 1, 2, 3, 4, 5};
 *    size_t len_ar = 20;
 *    @see{is_num_in_range_1_5} as callback with range to check [1; 5]
 *    mean_ar(ar, len_ar, is_num_in_range_1_5) => 3.000
 */
double mean_ar(const int ar[], size_t len_ar, int (*check_callback)(int)) {
  double sum = 0.0;
  size_t nums_count = 0;

  // get sum of @type{int} of the @link{ar}
  for (size_t i = 0; i < len_ar; i += 1) {
    if (check_callback(ar[i])) {
      sum += ar[i];
      nums_count += 1;
    }
  }

  return sum / (double)nums_count;
}
