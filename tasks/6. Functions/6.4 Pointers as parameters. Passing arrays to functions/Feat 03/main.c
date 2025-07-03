/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191305/step/5?unit=1204293}
 *
 */

#include <stdio.h>

#define ARR_LENGTH 20

int prod_ar(const int arr[], int arr_length);

/**
 *  @brief get the integers from input (space separated) to array and print
 *    to the console their product
 *
 *  @example
 *    1 2 3 4 5 6 7 8 => 40320
 */
int main(void) {
  int arr_of_int[ARR_LENGTH] = {0};
  int arr_prod = 1;

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

  // count the product of int
  // @note !always set only read quantity of int in the arr_of_int!
  arr_prod = prod_ar(arr_of_int, arr_elems_count);
  printf("%d\n", arr_prod);

  return 0;
}

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
