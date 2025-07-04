#include "./utils.h"

/**
 *  @brief Revert the @link{elems_quantity} of the @link{arr}
 *
 *  @note !Impure function! Mutates the original @link{arr} !
 *
 *  @param {short (*)[]} arr - array of numbers to be reverted
 *  @param {int} elems_quantity - qunatity of @link{arr} nums to revert
 *
 *  @return {void} - nothing
 *  @throw - if elems_quantity <= 0
 *
 *  @example
 *    short arr[10] = {-1, 0, 1, 2, 3, 4, 5, 6, 7, 8};
 *      reverse(arr, 3) => void
 *      arr{8, 7, 6, -1, 0, 1, 2, 3, 4, 5}
 */
void reverse(short arr[], int elems_quantity) {
  if (elems_quantity <= 0) {
    puts("Error: elems_quantity must be > 0");
    return;
  }

  // elems_quantity - 1 ?? => e.g. arr[6] => last num is at arr[6 - 1]
  // @note elems_quantity even or odd ?
  // e.g. arr[6] => middle num is at arr[2] (len / 2),
  //  arr[7] => middle num is at arr[3] ((len - 1) / 2)
  // @note but in C division is always integer division...)
  //  => 7 / 2 = 3 and 6 / 2 = 3
  for (int i = elems_quantity - 1, j = 0; j < elems_quantity / 2;
       i -= 1, j += 1) {
    short temp = arr[j];
    arr[j] = arr[i];
    arr[i] = temp;
  }
}
