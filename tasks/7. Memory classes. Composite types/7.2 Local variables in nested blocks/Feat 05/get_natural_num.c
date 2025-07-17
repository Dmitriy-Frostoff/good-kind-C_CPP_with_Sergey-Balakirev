#include "./utils.h"

/**
 *  @brief Get the natural num from the INPUT:
 *  @note ! Impure funcrion! Mutates the @link{n} !
 *
 *  @param {unsigned int *} n - pointer to variable to assign value
 *
 *  @return {1} - if not natural number or empty value was produced
 *  @return {0} - everything OK
 *
 *  @example
 *    unsigned int n;
 *    get_natural_num(&n) =>
 *      INPUT:
 *      5 => 0
 *      n{5}
 *
 *    unsigned int n;
 *    get_natural_num(&n) =>
 *      INPUT:
 *      '\0' => 1
 *      OUTPUT:
 *      "Error: expected one natural number 'n'"
 */
char get_natural_num(unsigned int *n) {
  if (scanf("%u", n) != 1 || n <= 0) {
    puts("Error: expected one natural number 'n'");
    return 1;
  }

  return 0;
}
