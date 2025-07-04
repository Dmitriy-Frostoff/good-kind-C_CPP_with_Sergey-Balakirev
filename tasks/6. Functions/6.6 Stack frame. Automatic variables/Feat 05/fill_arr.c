#include "./utils.h"

/**
 *  @brief Fill the @link{arr} from the INPUT:
 *
 *  @param {short (*)[]} arr - array to fill
 *  @param {size_t} arr_size - size of @link{arr}
 *
 *  @return {int} - quantity of added to the link{arr} nums
 *
 *  @example
 *    short arr[5] = {0};
 *    size_t arr_size = 5;
 *      fill_arr(arr, arr_size) =>
 *      INPUT:
 *      -1 0 1 2 3 => 5
 *      arr{-1, 0, 1, 2, 3}
 */
int fill_arr(short arr[], size_t arr_size) {
  int count = 0;
  while (count < arr_size && scanf("%hd", &arr[count]) == 1) {
    count += 1;
  }

  return count;
}
