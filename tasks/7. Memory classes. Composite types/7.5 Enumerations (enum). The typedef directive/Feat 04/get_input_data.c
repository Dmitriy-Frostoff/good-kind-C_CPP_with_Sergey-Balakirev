#include "./utils.h"

/**
 *  @brief Get the input data from the INPUT:
 *
 *  @note ! Impure function! Mutates the outer @link{variable} !
 *
 *  @param {int *} variable - variable to assign read value
 *
 *  @return {0} - everything OK
 *  @return {1} - problems via data reading from the INPUT:
 *
 *  @example
 *    int param = 0;
 *    get_input_data(&param) =>
 *    INPUT:
 *    42 => 0
 *    param{42}
 *
 *    get_input_data(&param) =>
 *    INPUT:
 *    '\0' => 1
 *    param{0}
 *
 */
int get_input_data(int *variable) {
  if (scanf("%d", variable) != 1) {
    puts("Error: empty input");
    return 1;
  }

  return 0;
}
