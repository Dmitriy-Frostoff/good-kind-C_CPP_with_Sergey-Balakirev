#include "./utils.h"

/**
 *  @brief Print to the console nums (space separated) of the @link{arr}
 *
 *  @param {double []} arr - array of real numbers to print
 *  @param {const int} NUMS_QUANTITY - quantity of nums to print
 *
 *  @example
 *    double arr[20] = {0.56 -65.43 0.10 11.00};
 *    print_arr_nums(arr, 4) => void
 *      OUTPUT:
 *      0.56 -65.43 0.10 11.00
 */
void print_arr_nums(const double arr[], const size_t NUMS_QUANTITY) {
  size_t arr_index = 0;

  while (arr[arr_index] != '\0') {
    // last num in the arr ? => no space separator
    if (arr_index == NUMS_QUANTITY - 1) {
      printf("%.2f", arr[arr_index]);
      break;
    }

    printf("%.2f ", arr[arr_index]);

    arr_index += 1;
  }
}
