#include "./utils.h"

/**
 *  @brief Get the integers from the input to the @link{arr}
 *
 *  @note !Impure function! Uses INPUT: and modifies @link{arr}
 *
 *  @param {short *} arr - array of integers
 *  @param {size_t} arr_size - size of @link{arr}
 *
 *  @return {size_t} - quantity of written nums
 *
 *  @example
 *    short arr[5] = {0};
 *    fill_arr_with_integers(arr, 5) =>
 *     INPUT:
 *     -1 0 1 2 3 => void
 *     arr{-1, 0, 1, 2, 3}
 */
size_t fill_arr_with_integers(short arr[], size_t arr_size) {
  size_t count = 0;
  while (count < arr_size && scanf("%hd", &arr[count]) != EOF) {
    count += 1;
  }

  return count;
}
