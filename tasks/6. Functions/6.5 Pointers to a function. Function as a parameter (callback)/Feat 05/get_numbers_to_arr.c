#include "./utils.h"

/**
 *  @brief Get the numbers from the input to @linl{arr}
 *
 *  @note !Impure function! Mutates the @link{arr}
 *
 *  @param {int[]} arr - array of integers
 *  @param {size_t} arr_size - size of @link{arr}
 *
 *  @return {int} - 0, everything is OK
 *
 *  @example
 *    int arr[20] = {0}
 *      get_numbers_to_arr(arr, 20) =>
 *      INPUT:
 *      1 2 3 4 5 => 0
 *      arr{1, 2, 3, 4, 5}
 */
int get_numbers_to_arr(int arr[], size_t arr_size) {
  int x = -1;
  int nums_count = 0;

  while (scanf("%d", &x) == 1) {
    if (nums_count == arr_size) {
      break;
    }

    arr[nums_count] = x;
    nums_count += 1;
  }

  return 0;
}
