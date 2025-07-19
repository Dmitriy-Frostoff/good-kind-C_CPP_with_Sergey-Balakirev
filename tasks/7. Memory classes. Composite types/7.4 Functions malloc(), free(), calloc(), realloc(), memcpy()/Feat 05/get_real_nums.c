#include "./utils.h"

/**
 *  @brief Get the real nums from the INPUT: to the @link{arr}
 *
 *  @note ! Impure function! Mutates the outer @link{arr} !
 *
 *  @param {double []} arr - array to fill
 *  @param {const size_t} SIZE_OF_ARR - size of @link{arr}
 *  @param {const size_t} MAX_NUM_COUNT - max nums quantity to read and nest to
 *    the @link{arr}
 *
 *  @return {size_t} - quantity of read numbers
 *
 *  @example
 *    double arr[20] = {0};
 *    arr_size = 20;
 *    max_num_to_read = 3;
 *    get_real_nums(arr, arr_size, max_num_to_read) =>
 *      INPUT:
 *      0.3 -1.2 7.4 3.2 8.3 1.0 5.4 => 3
 *      arr{0.3, -1.2, 7.4}
 *
 */
size_t get_real_nums(double arr[], const size_t SIZE_OF_ARR,
                     const size_t MAX_NUM_COUNT) {
  size_t counter = 0;
  double num = 0.0;

  while (scanf("%lf", &num) == 1 && counter <= MAX_NUM_COUNT) {
    arr[counter] = num;
    counter += 1;
  }

  return counter;
}
