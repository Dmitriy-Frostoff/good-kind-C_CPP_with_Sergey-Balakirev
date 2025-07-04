#include "./utils.h"

/**
 *  @brief print to the terminal real numbers rounded to hundreds
 *
 *  @param {double[]} arr - array of real numbers
 *  @param {int} len_arr - array length (or quantity of elems to print)
 *
 *  @example
 *    arr[20] = {0.56, -65.43, 0.10, 11.00}
 *    print_real_numbers(arr, 4) => >>> 0.56 -65.43 0.10 11.00
 */
void print_real_numbers(const double arr[], int len_arr) {
  for (int i = 0; i < len_arr; i += 1) {
    if (i == len_arr - 1) {
      printf("%.2f", arr[i]);
      break;
    }
    printf("%.2f ", arr[i]);
  }
}
