#include "./utils.h"

/**
 *  @brief Wrapper over the logic of counting sum via @link{ITEM} (=> chosen
 *    function)
 *
 *  @note Currently defined options for user input @link{ITEM}:
 *    1 => calculate sum of odd numbers
 *    2 => calculate sum of non-negative numbers
 *    3 => calculate sum of negative numbers
 *    4 => just calculate sum of all integers of @link{arr}
 *
 *  @param {int} ITEM - user chosen integer (1...4, ITEM > 0)
 *  @param {int (*)(const int arr[], size_t len_arr,
 *                          int (*check_callback)(const int))} sum_ar_callback -
 *    callback for calculating sum of @link{arr} integers via the criteria. e.g.
 *    @see{sum_ar}
 *  @param {const int[]} arr - array of marks
 *  @param {type} len_arr - length of @link{arr}
 *  @param {int (*[])(int)} funcs - array of pointers to the callbacks for
 *    checking @link{arr} nums to calculate sum of
 *  @param {size_t} sizeof_funcs - length of @link{funcs}
 *
 *  @return {int} - counted sum of @link{arr} integers
 *  @throw if @link{item} is < 1. Returns exit code -1
 *
 *  @example
 *    const int ITEM = 1;
 *    sum_ar - @see{sum_ar} for details;
 *    const arr[20] = {5, 4, 3, 5, 6, 78, 89, 56, , 43, , 456, 45, 645, 45, 44,
 *      3, 1, 4};
 *    len_arr = 20;
 *    int (*funcs[4])(int) = {is_odd, is_positive, is_negative, deflt};
 *      @see{is_odd}, @see{is_positive}, @see{is_negative}, @see{deflt} for
 *      details
 *    size_t sizeof_funcs = 4;
 *      count_sum_via_chosen_func(ITEM, sum_ar, len_arr, funcs, sizeof_funcs) =>
 *       884
 *       got the sum of "odd" numbers of the "arr" via "is_odd" checking func
 */
int count_sum_via_chosen_func(
    const int ITEM,
    int (*sum_ar_callback)(const int arr[], size_t len_arr,
                           int (*check_callback)(const int)),
    const int arr[], size_t len_arr, int (*funcs[])(int), size_t sizeof_funcs) {
  int sum = 0;

  if (ITEM - 1 < 0) {
    puts("Error: expected ITEM to be > 0");
    return -1;
  }

  switch (ITEM) {
  case 1:
    sum = sum_ar_callback(arr, len_arr, funcs[ITEM - 1]);
    break;
  case 2:
    sum = sum_ar_callback(arr, len_arr, funcs[ITEM - 1]);
    break;
  case 3:
    sum = sum_ar_callback(arr, len_arr, funcs[ITEM - 1]);
    break;
  default:
    sum = sum_ar_callback(arr, len_arr, funcs[sizeof_funcs - 1]);
    break;
  }

  return sum;
}
