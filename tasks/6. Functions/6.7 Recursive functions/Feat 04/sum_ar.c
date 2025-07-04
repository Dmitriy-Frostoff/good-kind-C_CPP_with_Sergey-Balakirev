#include "./utils.h"

/**
 *  @brief Count (recursively) sum of @link{arr}
 *
 *  @param {const short (*)} arr - pointer to the array of integers
 *  @param {size_t} LEN - quantity of @link{arr} nums
 *  @param {size_t} indx - index of @link{arr}
 *
 *  @return {int} - the counted value of sum of the @link{arr}
 *
 *  @example
 *    short arr[10] = {6, 4, 10};
 *    sum_ar(arr, 3, 0) => 20
 */
int sum_ar(const short *arr, const size_t LEN, size_t indx) {
  if (indx == LEN) {
    return 0;
  }

  /*
   * e.g. arr = {0, 1, 2}
   *  sum_ar(arr, 3, 0) =>
   *      return sum_ar(arr, 3, 0 + 1) + arr[0] =>
   *    call sum_ar(arr, 3, 1) =>
   *      return sum_ar(arr, 3, 1 + 1) + arr[1] =>
   *    call sum_ar(arr, 3, 2) =>
   *      return sum_ar(arr, 3, 2 + 1) + arr[2] =>
   *    call sum_ar(arr, 3, 3) => 0 (indx == LEN => 0) =>
   *      sum_ar(arr, 3, 2) == 0 + arr[2] => 2
   *      sum_ar(arr, 3, 1) == 2 + arr[1] => 3
   *      sum_ar(arr, 3, 0) == 3 + arr[0] => 3
   */

  return sum_ar(arr, LEN, indx + 1) + arr[indx];
}
