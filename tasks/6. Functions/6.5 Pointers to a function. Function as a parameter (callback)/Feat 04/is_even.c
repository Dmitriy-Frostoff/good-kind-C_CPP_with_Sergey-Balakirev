#include "./utils.h"

/**
 *  @brief Check that number is even or odd
 *
 *  @param {const int} num - number for check
 *
 *  @return {int} - 1, @link{num} is even
 *  @return {int} - 0, @link{num} is odd
 *
 *  @example
 *    is_even(2) => 1
 *    is_even(3) => 0
 *    is_even(0) => 1
 *    is_even(-42) => 1
 *    is_even(-17) => 1
 */
int is_even(int num) {
  return num % 2 == 0 ? 1 : 0;
}
