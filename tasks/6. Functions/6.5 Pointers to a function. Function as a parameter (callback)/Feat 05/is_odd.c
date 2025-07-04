#include "./utils.h"

/**
 *  @brief Check that number is odd
 *
 *  @param {const int} num - number for check
 *
 *  @return {int} - 1, @link{num} is odd
 *  @return {int} - 0, @link{num} is even
 *
 *  @example
 *    is_odd(2) => 0
 *    is_odd(3) => 1
 *    is_odd(0) => 0
 *    is_odd(-42) => 0
 *    is_odd(-17) => 1
 */
int is_odd(int num) {
  if (num >= 0) {
    return num % 2 != 0 ? 1 : 0;
  }

  return num % 2 != -0 ? 1 : 0;
}
