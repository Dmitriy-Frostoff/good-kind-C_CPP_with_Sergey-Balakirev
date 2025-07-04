/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191308/step/6?unit=1204296}
 *
 */

#include "./config.h"
#include "./utils.h"

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
