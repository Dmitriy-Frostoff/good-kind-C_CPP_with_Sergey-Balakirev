/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191308/step/6?unit=1204296}
 *
 */

#include <stddef.h>
#include <stdio.h>

#define MAX_LENGTH 20

int sum_ar(const short arr[], size_t LEN, size_t indx);
size_t fill_arr_with_integers(short arr[], size_t arr_size);

int main(void) {
  short arr[MAX_LENGTH] = {0};
  size_t arr_length = sizeof(arr) / sizeof(*arr);
  size_t arr_num_count = 0;
  int arr_sum;

  // fill @link{arr} with nums @type{short}
  arr_num_count = fill_arr_with_integers(arr, arr_length);

  // count @link{arr_sum} of arr integers
  arr_sum = sum_ar(arr, arr_num_count, 0);

  // print to the console the @link{arr_sum}
  printf("%d", arr_sum);

  return 0;
}

/**
 *  @brief Get the integers from the input to the @link{arr}
 *
 *  @note !Impure function! Uses INPUT: and modifies @link{arr}
 *
 *  @param {short *} arr - array of integers
 *  @param {size_t} arr_size - size of @link{arr}
 *
 *  @return {size_t} - quantity of written nums
 *
 *  @example
 *    short arr[5] = {0};
 *    fill_arr_with_integers(arr, 5) =>
 *     INPUT:
 *     -1 0 1 2 3 => void
 *     arr{-1, 0, 1, 2, 3}
 */
size_t fill_arr_with_integers(short arr[], size_t arr_size) {
  size_t count = 0;
  while (count < arr_size && scanf("%hd", &arr[count]) != EOF) {
    count += 1;
  }

  return count;
}

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
