#include "./utils.h"

/**
 *  @brief Print to the terminal space separated @link{elems_quantity} of
 *    @link{arr}
 *
 *  @param {short (*)[]} arr - array of numbers to be printed
 *  @param {type} elems_quantity - qunatity of @link{arr} nums to be printed
 *
 *  @return {void} - nothing
 *  @throw - if elems_quantity <= 0
 *
 *  @example
 *     short arr[10] = {-1, 0, 1, 2, 3, 4, 5, 6, 7, 8};
 *      print_first_N_nums(arr, 3) => void
 *      OUTPUT:
 *      8 7 6
 */
void print_first_N_nums(short arr[], int elems_quantity) {
  if (elems_quantity <= 0) {
    puts("Error: elems_quantity must be > 0");
    return;
  }

  for (int i = 0; i < elems_quantity; i += 1) {
    if (i == elems_quantity - 1) {
      printf("%d", arr[i]);
      break;
    }
    printf("%d ", arr[i]);
  }
}
