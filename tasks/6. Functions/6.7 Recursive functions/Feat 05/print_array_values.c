#include "./utils.h"

/**
 *  @brief Print to the console (space separated) the @link{qunatity_to_print}
 *    of numbers of the @link{arr}
 *
 *  @param {const short[]} arr - array of numbers
 *  @param {size_t} arr_size - @link{arr} size
 *  @param {size_t} qunatity_to_print - quantity of numbers to print
 *    ( @link{qunatity_to_print} <= @link{arr_size})
 *
 *  @example
 *    short arr[10] = {-1, 0, 1, 2, 3};
 *    print_array_values(arr, 10, 5) =>
 *    OUTPUT:
 *    -1 0 1 2 3 => void
 *
 *    short arr[5] = {-1, 0, 1, 2, 3};
 *    print_array_values(arr, 5, 7) =>
 *    OUTPUT:
 *    -1 0 1 2 3 => void
 */
void print_array_values(const short arr[], const size_t ARR_SIZE,
                        size_t qunatity_to_print) {
  // if were produced incorrect @link{qunatity_to_print} value
  if (qunatity_to_print > ARR_SIZE) {
    qunatity_to_print = ARR_SIZE;
  }

  // print values
  for (int i = 0; i < qunatity_to_print; i += 1) {
    if (i == qunatity_to_print - 1) {
      printf("%d", arr[i]);
      break;
    }
    printf("%d ", arr[i]);
  }
}
