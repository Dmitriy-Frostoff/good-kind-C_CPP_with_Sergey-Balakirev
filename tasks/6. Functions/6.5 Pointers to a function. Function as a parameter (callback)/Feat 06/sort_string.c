#include "./utils.h"

/**
 *  @brief Sort @link{str} chars via chosen callback @link{match_ab}
 *
 *  @note !Impure function! Mutates the original @link{str}
 *  @note Sorting function is based on the "Selection Sort" algorithm
 *
 *  @param {char *} str - valid string for sorting its chars
 *  @param {size_t} max_len - quantity of chars int the @link{str}
 *    (not the entire char str[] size!)
 *  @param {int (*)(const char a, const charb)} match_ab - callback for
 *    comparing chars logic
 *  @return {void} - nothing to return
 *
 *  @example
 *    char str[100] = "Phone number: 7845037856221";
 *    max_len = 27;
 *    compare_callback - match_ab @see{match_ab}
 *      sort_string(str, max_len, match_ab) =>
 *        "0122345567788  :Pbeehmnnoru"
 */
void sort_string(char *str, size_t max_len,
                 int (*compare_callback)(const char, const char)) {
  size_t current_index;
  // fix for case if "someone" pass the entire size of @link{str}
  //  instead of str_len
  max_len = strlen(str);

  for (size_t i = 0; i < max_len - 1; i += 1) {
    current_index = i;

    for (size_t j = i + 1; j < max_len; j += 1) {
      if (!match_ab(str[current_index], str[j])) {
        current_index = j;
      }
    }

    // index is not the same as at the begining ? =>
    if (current_index != i) {
      // swap str values at current_index and i
      char temp = str[current_index];
      str[current_index] = str[i];
      str[i] = temp;
    }
  }
}
