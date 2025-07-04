#include "./utils.h"

/**
 *  @brief Get four integers from the input
 *
 *  @note !Impure function! It mutates the originals values of params
 *
 *  @param {int *} num_1 - integer
 *  @param {int *} num_2 - integer
 *  @param {int *} num_3 - integer
 *  @param {int *} num_4 - integer
 *
 *  @return {int} - 0, everything OK
 *  @throw if empty data was produced and return exit code 1
 *
 *  @example
 *    int num_1, num_2, num_3, num_4;
 *      get_integers(&num_1, &num_2, &num_3, &num_4) =>
 *      INPUT:
 *      1 2 3 -4 => 0
 *      num_1 = 1; num_2 = 2; num_3 = 3; num_4 = -4;
 */
int get_integers(int *num_1, int *num_2, int *num_3, int *num_4) {
  if (scanf("%d %d %d %d", num_1, num_2, num_3, num_4) != 4) {
    puts("Error: expected 4 integers");
    return 1;
  }

  return 0;
}
