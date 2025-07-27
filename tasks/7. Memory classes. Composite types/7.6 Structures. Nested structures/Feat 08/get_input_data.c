#include "./utils.h"

/**
 *  @brief Get the input data from the INPUT: and assign it to the three
 *  variables
 *
 *  Expected three space separated integers of @type{int} (coordinates x, y, z)
 *
 *  @note ! Impure function !
 *  - Mutates the outer @link{var_1}, @link{var_2}, @link{var_3}
 *
 *  @param {int *} var_1 - variable to assign read value (coordinate x)
 *  @param {int *} var_2 - variable to assign read value (coordinate y)
 *  @param {int *} var_3 - variable to assign read value (coordinate z)
 *
 *  @return {0} - everything OK
 *  @return {-1} - problems via data reading from the INPUT:
 *  @throw if not 3 integers were read or some problems occured
 *
 *  @example
 *    char param_1 = 0;
 *    char param_2 = 0;
 *    char param_3 = 0;
 *
 *    get_input_data(&param_1, &param_2, &param_3) =>
 *    INPUT:
 *    7 8 9 => 0
 *    param_1 = 7
 *    param_2 = 8
 *    param_3 = 9
 *
 *    get_input_data(&param_1, &param_2, &param_3) =>
 *    INPUT:
 *    '\0' => -1
 *    param_1 = 0
 *    param_2 = 0
 *    param_3 = 0
 *
 */
int get_input_data(int *var_1, int *var_2, int *var_3) {
  if (scanf("%d %d %d", var_1, var_2, var_3) != 3) {
    return -1;
  }

  return 0;
}
