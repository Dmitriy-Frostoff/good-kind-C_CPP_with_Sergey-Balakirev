#include "./utils.h"

/**
 *  @brief Get the input data from the INPUT: and assign it to the variable (if
 *  data is positive integer)
 *
 *  @note ! Impure function !
 *  - Mutates the outer @link{rubs}
 *
 *  @param {int *} rubs - address of the variable to assign read value
 *
 *  @return {0} - everything OK
 *  @return {-1} - problems via data reading from the INPUT:
 *  @throw if not 1 positive integer was read or some problems occured
 *
 *  @example
 *    int rubs = 0;
 *
 *    get_input_data(&rubs) =>
 *    INPUT:
 *    42 => 0
 *    rubs = 42
 *
 *    get_input_data(&rubs) =>
 *    INPUT:
 *    '\0' => -1
 *    rubs = 0
 *
 */
int get_input_data(int *rubs) {
  int temp_var = 0;

  if (scanf("%d", &temp_var) != 1 || temp_var < 0) {
    puts("Error(get_input_data function): expected one positive integer of "
         "type int");
    return -1;
  }

  // assigning value to the @link{rubs}
  *rubs = temp_var;

  return 0;
}
