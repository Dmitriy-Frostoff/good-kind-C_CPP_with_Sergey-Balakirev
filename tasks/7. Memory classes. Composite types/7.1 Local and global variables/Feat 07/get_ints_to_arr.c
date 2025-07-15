#include "./utils.h"

/**
 *  @brief Get integers from the INPUT: of @link{SIZE_OF_ARR} quantity and save
 *  them to the @link{arr}
 *
 *  @note ! Impure function! Mutates the original @link{arr} !
 *
 *  @param {int []} arr - array to fill
 *  @param {size_t} SIZE_OF_ARR - size of @link{arr}
 *
 *  @return {size_t} - quantity of written nums
 *
 *  @example
 *    int arr[20] = {0};
 *    size_t SIZE_OF_ARR = 20;
 *    get_ints_to_arr(arr, SIZE_OF_ARR) =>
 *    INPUT:
 *    -5 -3 -2 0 1 2 3 4 5 => 9
 *    arr{-5, -3, -2, 0, 1, 2, 3, 4, 5}
 */
size_t get_ints_to_arr(int arr[], const size_t SIZE_OF_ARR) {
  int x = 0;
  size_t num_count = 0;

  while (scanf("%d", &x) == 1) {
    arr[num_count] = x;
    num_count += 1;

    if (num_count == SIZE_OF_ARR) {
      break;
    }
  }

  return num_count;
}
