#include "./utils.h"

/**
 *  @brief Check that integer is in range [1; 5]
 *
 *  @param {const int} NUM - number to check
 *
 *  @return {int} - 1 if @link{NUM} in range, 0 otherwise
 *
 *  @example
 *    is_num_in_range_1_5(0) => 0
 *    is_num_in_range_1_5(1) => 1
 *    is_num_in_range_1_5(3) => 1
 *    is_num_in_range_1_5(5) => 1
 *    is_num_in_range_1_5(6) => 0
 *    is_num_in_range_1_5(-1) => 0
 *    is_num_in_range_1_5(42) => 0
 */
int is_num_in_range_1_5(const int NUM) {
  if (NUM >= 1 && NUM <= 5) {
    return 1;
  }

  return 0;
}
