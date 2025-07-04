#include "./utils.h"

/**
 *  @brief Get the sum of two the greatest of four integers
 *
 *  @param {int} a - number
 *  @param {int} b - number
 *  @param {int} c - number
 *  @param {int} d - number
 *
 *  @return {int} - sum of two the greatest numbers
 *
 *  @example
 *    sum_big2(0, 1, 2, 3, get_max_of_two_nums) => 5
 *    sum_big2(0, 1, 3, 3, get_max_of_two_nums) => 6
 */
int sum_big2(int a, int b, int c, int d) {
  int arr[4] = {a, b, c, d};
  size_t arr_length = sizeof(arr) / sizeof(*arr);

  // to choose the least value instead of NULL (C doesn't have NULL as empty
  //  value like NULL in TypeScript)
  int sum = a + b + c + d;
  int max_num = sum > 0 ? -sum : sum;
  int max_num_prev = max_num;

  for (size_t i = 0; i < arr_length; i += 1) {
    // if there're duplications in the @link{arr}
    if (arr[i] == max_num) {
      max_num_prev = max_num;
      continue;
    }

    // get the max num
    if (arr[i] > max_num) {
      max_num_prev = max_num;
      max_num = arr[i];
      continue;
    }

    // if current num is not the greatest, but greater than prev max
    if (arr[i] > max_num_prev && arr[i] < max_num) {
      max_num_prev = arr[i];
      continue;
    }
  }

  return max_num + max_num_prev;
}
