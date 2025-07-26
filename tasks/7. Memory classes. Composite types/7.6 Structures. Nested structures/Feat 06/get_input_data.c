#include "./utils.h"

/**
 *  @brief Get the input data from the INPUT: and assign it to the three
 *  variables
 *
 *  Expected three comma separated non - negative integers of @type{short}
 *
 *  @note ! Impure function !
 *  - Mutates the outer @link{variable_1}, @link{variable_2}, @link{variable_3}
 *
 *  @param {short *} variable_1 - variable to assign read value
 *  @param {short *} variable_2 - variable to assign read value
 *  @param {short *} variable_3 - variable to assign read value
 *
 *  @return {0} - everything OK
 *  @return {-1} - problems via data reading from the INPUT:
 *  @throw if not 3 integers were read or some problems occured
 *  @throw if not 3 non-negative integers were produced
 *
 *  @example
 *    short param_1 = 0;
 *    short param_2 = 0;
 *    short param_3 = 0;
 *
 *    get_input_data(&param_1, &param_2, &param_3) =>
 *    INPUT:
 *    42, 24, 12 => 0
 *    param_1{42}
 *    param_2{24}
 *    param_3{12}
 *
 *    get_input_data(&param_1, &param_2, &param_3) =>
 *    INPUT:
 *    '\0' => -1
 *    param_1 = 0
 *    param_2 = 0
 *    param_3 = 0
 *
 */
int get_input_data(short *variable_1, short *variable_2, short *variable_3) {
  if (scanf("%hd, %hd, %hd", variable_1, variable_2, variable_3) != 3) {
    puts("Error(get_input_data function): expected three comma separated "
         "integers of type short");
    return -1;
  }

  if (*variable_1 <= 0 || *variable_2 <= 0 || *variable_3 <= 0) {
    puts("Error(get_input_data function): expected three comma separated "
         "non-negative integers of type short");
    return -1;
  }

  return 0;
}
