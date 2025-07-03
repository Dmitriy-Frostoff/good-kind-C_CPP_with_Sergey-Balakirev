/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191305/step/4?unit=1204293}
 *
 */

#include <stdio.h>

#define ARR_LENGTH 10

int sum_ar(const int arr[], int arr_length);

/**
 *  @brief get the integers from input (space separated) to array and print
 *    to the console their sum
 *
 *  @example
 *    1 2 3 4 4 3 -2 -1 => 14
 */
int main(void) {
  int arr_of_int[ARR_LENGTH] = {0};
  int arr_sum = 0;

  // fill arr_of_int with integers
  int arr_elems_count = 0;
  int input_info = 0;
  while (arr_elems_count < ARR_LENGTH) {
    input_info = scanf("%d", &arr_of_int[arr_elems_count]);

    if (input_info == 0 || input_info == EOF) {
      break;
    }

    arr_elems_count += 1;
  }

  // count sum
  // @note !set only read arr_elems_count, not the entire arr_length!
  arr_sum = sum_ar(arr_of_int, arr_elems_count);
  printf("%d\n", arr_sum);

  return 0;
}

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
