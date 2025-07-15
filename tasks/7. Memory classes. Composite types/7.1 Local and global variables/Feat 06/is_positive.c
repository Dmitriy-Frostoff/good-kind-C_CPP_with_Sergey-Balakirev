#include "./utils.h"

/**
 *  @brief Check that @link{NUM} is >= 0
 *
 *  @param {const int} NUM - integer to check
 *
 *  @return {int} - 1 if @link{NUM} >= 0, or 0 otherwise
 *
 *  @example
 *    is_positive(0) => 1
 *    is_positive(42) => 1
 *    is_positive(-42) => 0
 */
int is_positive(const int NUM) {
  if (NUM >= 0) {
    return 1;
  }

  return 0;
}
