#include "./sum_ar.h"

/**
 *  @brief count sum of array integers
 *
 *  @param {int[]} arr - array of integers
 *  @param {int} arr_length - array length
 *
 *  @return {int} - sum of array integers
 *
 *  @example
 *    arr{1, 2, 3, 4, 4, 3, -2, -1, 4, 2} (10 nums), arr length = 10
 *      sum_ar(arr, 10) => 20
 *    arr{1, 2, 3, 4, 4, 3, -2, -1, 4, 2, 4, 2} (12 nums), arr length = 10
 *      sum_ar(arr, 10) => 20
 *    arr{1, 2, 3, 4, 4, 3, -2, -1} (8 nums), arr length = 10
 *      sum_ar(arr, 8) => 14
 */
int sum_ar(const int arr[], int arr_length) {
  int arr_sum = 0;

  for (int i = 0; i < arr_length; i += 1) {
    arr_sum += arr[i];
  }

  return arr_sum;
}
