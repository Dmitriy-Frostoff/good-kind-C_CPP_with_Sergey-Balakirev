#include "./utils.h"

/**
 *  @brief Get the integers from the INPUT: and save them to the @link{arr}
 *
 *  @note ! Impure function! Mutates the outer @link{arr} !
 *
 *  @param {short []} arr - array to fill
 *  @param {const size_t} SIZE_OF_ARR - size of @link{arr}
 *  @param {const size_t} MAX_NUM_COUNT - max nums quantity to read and nest to
 *    the @link{arr}
 *
 *  @return {size_t} - quantity of read numbers
 *
 *  @example
 *    short arr[20] = {0};
 *    arr_size = 20;
 *    max_num_to_read = 3;
 *    get_int_nums(arr, arr_size, max_num_to_read) =>
 *      INPUT:
 *      1 5 4 3 8 10 => 6
 *      arr{1, 5, 4}
 *
 */
int get_int_nums(short arr[], const size_t SIZE_OF_ARR,
                 const size_t MAX_NUM_COUNT) {
  int counter = 0;
  short num = 0;

  while (scanf("%hd", &num) == 1 && counter < MAX_NUM_COUNT) {
    arr[counter] = num;
    counter += 1;
  }

  return counter;
}
