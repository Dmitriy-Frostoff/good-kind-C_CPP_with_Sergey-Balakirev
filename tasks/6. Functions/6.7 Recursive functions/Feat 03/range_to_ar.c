#include "./utils.h"

/**
 *  @brief Fill (recursively) @link{ptr_a} with integers [ @link{from} :
 *    @link{TO} ]
 *
 *  @note !Impure function! Mutates the @link{ptr_a} array
 *
 *  @param {int (*)[]} ptr_a - pointer to the array
 *  @param {const size_t} MAX_LEN - @link{ptr_a} arr size
 *  @param {int} from - start integer of range to fill @link{ptr_a} with
 *  @param {const int} TO - last integer
 *  @param {size_t} count - quantity of added integers to the @link{ptr_a}
 *
 *  @return {size_t} - @link{count} value
 *
 *  @example
 *    int arr[20] = {0};
 *    range_to_ar(arr, 20, 1, 8, 0) => 8
 *      arr{1, 2, 3, 4, 5, 6, 7, 8, {0 x 12}}
 *    range_to_ar(arr, 10, 1, 12, 0) => 10
 *      arr{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, {0 x 10}}
 */
size_t range_to_ar(int *ptr_a, const size_t MAX_LEN, int from, const int TO,
                   size_t count) {
  ptr_a[count] = from;
  count += 1;

  if (from == TO || count == MAX_LEN) {
    return count;
  }

  // increase values
  from += 1;

  return range_to_ar(ptr_a, MAX_LEN, from, TO, count);
}
