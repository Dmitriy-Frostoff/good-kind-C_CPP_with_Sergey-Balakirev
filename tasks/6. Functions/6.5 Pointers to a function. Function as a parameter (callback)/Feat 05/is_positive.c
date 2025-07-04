#include "./utils.h"

/**
 *  @brief Check that number is non-negative (>=0)
 *
 *  @param {const int} num - number for check
 *
 *  @return {int} - 1, @link{num} is non - negative
 *  @return {int} - 0, @link{num} is negative
 *
 *  @example
 *    is_positive(2) => 1
 *    is_positive(0) => 1
 *    is_positive(-42) => 0
 */
int is_positive(int num) {
  return num >= 0 ? 1 : 0;
}
