#include "./utils.h"

/**
 *  @brief Print elems to the console (space separated)
 *
 *  @note Depends on @link{NOTES} enum
 *
 *  @param {const NOTES[]} arr - array of elems to print
 *  @param {size_t} arr_size - size of @link{arr}
 *  @param {type} quantity - quantity of elems to print
 *
 *  @example
 *    NOTES major_notes_arr[5] = {1, 3, 5};
 *    size_t major_notes_arr_size = 5;
 *    print_major_notes(major_notes_arr, major_notes_arr_size, 3); => void
 *    OUTPUT:
 *    1 3 5
 */
void print_major_notes(const NOTES arr[], size_t arr_size, size_t quantity) {
  // prevent out of range stepping
  if (quantity > arr_size) {
    quantity = arr_size;
  }

  for (size_t i = 0; i < quantity; i += 1) {
    // last elem ? => do not add ' '
    if (i == quantity - 1) {
      printf("%d", arr[i]);
      break;
    }
    printf("%d ", arr[i]);
  }
}
