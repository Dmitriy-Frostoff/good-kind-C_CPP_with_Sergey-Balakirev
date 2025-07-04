#include "./utils.h"

/**
 *  @brief Get the criteria from the input for summing
 *  @note !Impure function! Uses the INPUT
 *
 *
 *  @param {int} criteria - number for chosing
 *
 *  @return {int} - the @linl{criteria} value
 *  @throw if empty data was produced with exit code -1
 *
 *  @example
 *    get_criteria_for_sum() =>
 *    INPUT:
 *    1 => 1
 */
int get_criteria_for_sum(void) {
  int item = 0;
  if (scanf("%d", &item) != 1) {
    puts("Error: incorrect input");
    return -1;
  };

  return item;
}
