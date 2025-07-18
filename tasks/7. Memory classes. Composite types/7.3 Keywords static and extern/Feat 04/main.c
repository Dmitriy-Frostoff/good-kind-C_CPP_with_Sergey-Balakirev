/**
 *  The task description is at
 *  @link{https://stepik.org/lesson/1191312/step/6?unit=1204300}
 *
 *
 *  Create function `int range(void);` without global variable usage.
 *  Every call to @callback{range} function returns integers starting from 5 and
 *  than with step 3, e.g. 5, 8, 11, 14, 17 ...
 *
 *  Call @callback{range} function 7 times and print got integers to the console
 *  (spcae separated)
 *
 */

#include "./config.h"
#include "./utils.h"

int main(void) {
  int arr[ARR_SIZE] = {0};
  size_t arr_size = sizeof(arr) / sizeof(*arr);

  // fill @link{arr} with the results of @callback{range}
  for (int i = 0; i < NUMS_COUNT_TO_PRINT; i += 1) {
    arr[i] = range();
  }

  // print 7 nums space separated
  print_integers(arr, arr_size, NUMS_COUNT_TO_PRINT);

  return 0;
}
