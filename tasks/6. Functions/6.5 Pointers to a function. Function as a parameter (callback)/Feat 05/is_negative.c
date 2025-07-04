#include "./utils.h"

/**
 *  @brief Check that number is negative
 *
 *  @param {const int} num - number for check
 *
 *  @return {int} - 1, @link{num} is negative
 *  @return {int} - 0, @link{num} is  non - negative
 *
 *  @example
 *    is_negative(2) => 0
 *    is_negative(0) => 0
 *    is_negative(-42) => 1
 */
int is_negative(int num) {
  return num < 0 ? 1 : 0;
}
