#include "./utils.h"

/**
 *  @brief Get the input notes in range [1;7] to the @link{arr}
 *
 *  @note ! Impure function! Mutates the outer @link{arr} !
 *  @note Depends on global @typedef{NOTES}
 *
 *  @param {NOTES []} arr - array of @link{NOTES} type
 *  @param {size_t} arr_size - size of @link{arr}
 *
 *  @return {size_t} - quantity of added notes
 *
 *  @example
 *    NOTES arr[5] = {0};
 *    size_t arr_size = 5;
 *    get_input_data(arr, arr_size) =>
 *    INPUT:
 *    1 2 3 2 5 => 5
 *    arr{1, 2, 3, 2, 5}
 *
 *    get_input_data(arr, arr_size) =>
 *    INPUT:
 *    1 2 '\0' 2 5 => 2
 *    arr{1, 2}
 *
 */
size_t get_input_data(NOTES arr[], size_t arr_size) {
  size_t count = 0;
  int note = 0;

  while (count < arr_size) {
    if (scanf("%d", &note) != 1) {
      return count;
    }

    // add @link{note} to the @link{arr}
    arr[count] = note;

    count += 1;
  }

  return count;
}
