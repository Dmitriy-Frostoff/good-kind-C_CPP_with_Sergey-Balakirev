#include "./utils.h"

/**
 *  @brief Get the max range value from the input
 *
 *  @return {int} - max range value
 *  @throw if input is empty
 *
 *  @example
 *    get_max_range_value() =>
 *    INPUT:
 *    8 => 8
 */
int get_max_range_value() {
  int max_range_value;

  if (scanf("%d", &max_range_value) != 1) {
    puts("Error: empty input data");
    return -1;
  }

  return max_range_value;
}
