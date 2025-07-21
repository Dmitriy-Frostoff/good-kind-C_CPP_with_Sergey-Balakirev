#include "./utils.h"

/**
 *  @brief Print space separated the @link{nums_count_to_print} of the
 *    @link{ARR} to the console
 *
 *  @param {const int []} ARR - array of nums to print
 *  @param {const size_t} SIZE_OF_ARR - size of @link{ARR}
 *  @param {size_t} nums_count_to_print - quantity of nums to print
 *
 *  @example
 *    unsigned int arr[10] = {0, 1, 2, 3, 5, 8}
 *    size_t arr_size = 10;
 *    print_integers(arr, arr_size, 4) => void
 *      OUTPUT:
 *      0 1 2 3
 *    print_integers(arr, arr_size, 50) => void
 *      OUTPUT:
 *      0 1 2 3 5 8 0 0 0 0
 *      only 10 nums was printed
 */
void print_integers(const int ARR[], const size_t SIZE_OF_ARR,
                    size_t nums_count_to_print) {
  // check the @link{nums_count_to_print}
  if (nums_count_to_print > SIZE_OF_ARR) {
    nums_count_to_print = SIZE_OF_ARR;
  }

  for (size_t i = 0; i < nums_count_to_print; i += 1) {
    // last num in ARR ? => do not add ' ' separator
    if (i == nums_count_to_print - 1) {
      printf("%d", ARR[i]);
      break;
    }

    printf("%d ", ARR[i]);
  }
}
