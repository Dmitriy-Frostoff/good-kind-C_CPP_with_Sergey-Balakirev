#include "./utils.h"

/**
 *  @brief Count mean of the arbitary count of integers
 *
 *  @param {int} total - quantity of the integers to count
 *  @param {int} ... - integers ( of @link{total} quantity) to count mean
 *
 *  @return {double} - counted mean of the arbitary count of params
 *
 *  @example
 *    mean(3, 0, 1, 2, 3, 4) => 1
 *      (0 + 1 + 2) / 3 => 1 (everything after total(i.e. 3 here) will be
 *      omitted)
 *
 */
double mean(int total, ...) {
  double sum = 0.0;

  // setup the arbitary variables usage
  va_list arg;

  va_start(arg, total);

  // count mean of the integers
  for (int i = 0; i < total; i += 1) {
    sum += va_arg(arg, int);
  }

  // complete the iteration cycles
  va_end(arg);

  // return counted mean
  return (sum / (double)total);
}
