#include "./utils.h"

/**
 *  @brief Get the integers from the INPUT: and save them to the @link{arr}
 *
 *  @note ! Impure function! Mutates the outer @link{arr} !
 *
 *  @param {int []} arr - array to fill
 *  @param {const size_t} SIZE_OF_ARR - size of @link{arr}
 *  @param {const size_t} MAX_NUM_COUNT - max nums quantity to read and nest to
 *    the @link{arr}
 *
 *  @return {size_t} - quantity of read numbers
 *
 *  @example
 *    int arr[20] = {0};
 *    arr_size = 20;
 *    max_num_to_read = 3;
 *    get_int_nums(arr, arr_size, max_num_to_read) =>
 *      INPUT:
 *      1 5 4 3 8 10 => 6
 *      arr{1, 5, 4}
 *
 */
size_t get_int_nums(int arr[], const size_t SIZE_OF_ARR,
                    const size_t MAX_NUM_COUNT) {
  size_t counter = 0;
  int num = 0;

  while (scanf("%d", &num) == 1 && counter <= MAX_NUM_COUNT) {
    arr[counter] = num;
    counter += 1;
  }

  return counter;
}
