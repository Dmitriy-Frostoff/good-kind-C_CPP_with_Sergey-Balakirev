#include "./utils.h"

/**
 *  @brief Get the prime factors via eratosthen sieve and save them to the
 *    @link{arr}
 *
 *  @note ! Impure function! Depends on macros @link{PRIME_FACTORS_QUANTITY} and
 *    creates array inside of that size!!!
 *  @note ! Impure function! Mutates the original @link{arr} !
 *
 *  @param {signed short} arr - array to fill with prime factors
 *  @param {size_t} arr_size - size of @link{arr}
 *
 *  @example
 *    unsigned short arr[20] = {0};
 *    size_t arr_size = 20;
 *    get_eratosthen_sieve(arr, arr_size) => void
 *      arr{2, 3, 5, 7, 11, 13, 17, 19}
 *
 */
void get_eratosthen_sieve(unsigned short arr[], size_t arr_size) {
  if (arr_size == 0) {
    return;
  }

  // assume that the entire @link{temp_arr} are of all the non prime factors at
  // the begining (@note in C array always is initialized with 0 i.e. assumes of
  // @type{false} )
  unsigned short temp_arr[PRIME_FACTORS_QUANTITY] = {false};
  size_t temp_arr_size = sizeof(temp_arr) / sizeof(*temp_arr);
  size_t arr_index = 0;

  // 0 and 1 are not prime factors
  temp_arr[0] = true;
  temp_arr[1] = true;

  // i = 2 ? => 2 is a first prime factor
  for (unsigned short i = 2; i < (unsigned short)temp_arr_size; i += 1) {
    if (temp_arr[i] == false) {
      // fill the outer @link{arr} with found prime factors (i.e. with indexes
      // of @link{temp_arr} that value is @type{false})
      if (arr_index < arr_size) {
        arr[arr_index] = i;
        arr_index += 1;
      }

      // set all the cases of the arr[i * k] (e.g. 2 * 1, 2 * 2, 2 * 3) count of
      // the current prime factor to true
      for (unsigned short k = 1; k <= (unsigned short)ceil(temp_arr_size / 2);
           k += 1) {
        unsigned short curr_index = i * k;

        // prevent out of @link{temp_arr_size} range assigning
        if (curr_index > temp_arr_size - 1) {
          break;
        }

        // prevent extra assigning
        if (temp_arr[curr_index] == false) {
          temp_arr[curr_index] = true;
        }
      }
    }
  }
}
