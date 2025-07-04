#include "./utils.h"

/**
 *  @brief Print to the termnal first @link{quantity_to_print} nums
 *  (space separated)
 *
 *  @note if @link{quantity_to_print} is greater than @link{sizeof_arr} will be
 *  printed only @link{sizeof_arr} nums
 *
 *  @param {const int (*)[]} arr - pointer to the array of integers
 *  @param {size_t} sizeof_arr - size of @link{arr}
 *  @param {size_t} quantity_to_print - quantity of nums to print
 *
 *  @throw if @link{sizeof_arr} or @link{quantity_to_print} are == 0
 *
 *  @example
 *    int arr[10] = {-1, 0, 1, 2, 3};
 *    size_t quantity_to_print = 4
 *    print_arr_nums(arr, 10, quantity_to_print) => void
 *    OUTPUT:
 *    -1 0 1 2
 */
void print_arr_nums(const int arr[], const size_t SIZEOF_ARR,
                    size_t quantity_to_print) {
  if (SIZEOF_ARR == 0) {
    puts("Error: array size is 0");
    return;
  }

  if (quantity_to_print == 0) {
    puts("Error: nums quantity for printing is 0");
    return;
  }

  // protection from step over the @link{arr}
  if (quantity_to_print > SIZEOF_ARR) {
    quantity_to_print = SIZEOF_ARR;
  }

  for (size_t i = 0; i < quantity_to_print; i += 1) {
    if (i == quantity_to_print - 1) {
      printf("%d", arr[i]);
      break;
    }
    printf("%d ", arr[i]);
  }
}
