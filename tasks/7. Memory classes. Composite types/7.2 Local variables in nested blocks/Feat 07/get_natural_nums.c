#include "./utils.h"

/**
 *  @brief Get the space separated natural nums from the INPUT:
 *  @note ! Impure funcrion! Mutates the @link{n} and @link{m} !
 *
 *  @param {int *} n - pointer to variable to assign value
 *  @param {int *} m - pointer to variable to assign value
 *
 *  @return {1} - if not natural number or empty value was produced
 *  @return {0} - everything OK
 *
 *  @example
 *    int n;
 *    int m;
 *    get_natural_nums(&n, &m) =>
 *      INPUT:
 *      5 10 => 0
 *      n{5}
 *      m{10}
 *
 *    int n;
 *    get_natural_nums(&n) =>
 *      INPUT:
 *      '\0' => 1
 *      OUTPUT:
 *      "Error: expected two natural numbers 'n m' space separated"
 */
char get_natural_nums(int *n, int *m) {
  if (scanf("%d %d", n, m) != 2 || n <= 0 || m <= 0) {
    puts("Error: expected two natural numbers 'n m' space separated");
    return 1;
  }

  return 0;
}
