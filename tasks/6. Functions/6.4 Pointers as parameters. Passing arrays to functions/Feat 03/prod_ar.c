#include "./prod_ar.h"

/**
 *  @brief count product of the array integers
 *
 *  @param {int[]} arr - array of integers
 *  @param {int} arr_length - array length
 *
 *  @return {int} - product of the array integers
 *
 *  @example
 *    arr{1, 2, 3, 4, 5, 6, 7, 8, \0} (8 nums), arr length = 20
 *      prod_ar(arr, 8) => 40320
 *    arr{4, \0} (1 num), arr length = 20
 *      prod_ar(arr, 1) => 4
 *
 */
int prod_ar(const int arr[], int arr_length) {
  int arr_prod = 1;

  for (int i = 0; i < arr_length; i += 1) {
    arr_prod *= arr[i];
  }

  return arr_prod;
}
