#include "./utils.h"

/**
 *  @brief Validate data to fit time etalon h[0:23] m[0:59] s[0:59]
 *
 *  @note ! Impure function !
 *  - implicit dependence on global variables @link{HOURS}, @link{MINUTES},
 *    @link{SECONDS}
 *
 *  @param {const char} temp_var_1 - value of variable (hours)
 *  @param {const char} temp_var_2 - value of variable (minutes)
 *  @param {const char} temp_var_3 - value of variable (seconds)
 *  @param {const char} temp_var_4 - value of variable (hours)
 *  @param {const char} temp_var_5 - value of variable (minutes)
 *  @param {const char} temp_var_6 - value of variable (seconds)
 *
 *  @return {1} - true, variables passed the check
 *  @return {0} - false, variables not passed the check
 *
 *  @example
 *    char param_1 = 12;
 *    char param_2 = 45;
 *    char param_3 = 16;
 *    char param_4 = 4;
 *    char param_5 = 23;
 *    char param_6 = 48;
 *
 *    validate_time_parts(param_1, param_2, param_3, param_4, param_5, param_6)
 *      => 1
 *
 *    char param_1 = 24;
 *    char param_2 = 45;
 *    char param_3 = 16;
 *    char param_4 = -4;
 *    char param_5 = 23;
 *    char param_6 = 61;
 *
 *    validate_time_parts(param_1, param_2, param_3, param_4, param_5, param_6)
 *      => 0
 *    param_1 out of range[0:24], param_4 out of range[0:24], param_6 out of
 *      range[0:59]
 *
 */
static char validate_time_parts(const char TEMP_VAR_1, const char TEMP_VAR_2,
                                const char TEMP_VAR_3, const char TEMP_VAR_4,
                                const char TEMP_VAR_5, const char TEMP_VAR_6) {
  // negative path check
  if ((TEMP_VAR_1 < 0 || TEMP_VAR_1 >= HOURS) ||
      (TEMP_VAR_2 < 0 || TEMP_VAR_2 >= MINUTES) ||
      (TEMP_VAR_3 < 0 || TEMP_VAR_3 >= SECONDS) ||
      (TEMP_VAR_4 < 0 || TEMP_VAR_4 >= HOURS) ||
      (TEMP_VAR_5 < 0 || TEMP_VAR_5 >= MINUTES) ||
      (TEMP_VAR_6 < 0 || TEMP_VAR_6 >= SECONDS)) {
    return 0;
  }

  return 1;
}

/**
 *  @brief Get the input data from the INPUT: and assign it to the six
 *  variables
 *
 *  Expected six space separated positive integers of @type{char} like
 *  hh[0:23] mm[0:59] ss[0:59] hh[0:23] mm[0:59] ss[0:59] (time data)
 *
 *  @note ! Impure function !
 *  - Mutates the outer @link{var_1}, @link{var_2}, @link{var_3}, @link{var_4},
 *    @link{var_5}, @link{var_6}
 *  - implicit dependence on global variables @link{HOURS}, @link{MINUTES},
 *    @link{SECONDS}
 *  - implicit dependence on @see{validate_time_parts} function
 *
 *  @param {unsigned char *} var_1 - variable to assign read value (hours)
 *  @param {unsigned char *} var_2 - variable to assign read value (minutes)
 *  @param {unsigned char *} var_3 - variable to assign read value (seconds)
 *  @param {unsigned char *} var_4 - variable to assign read value (hours)
 *  @param {unsigned char *} var_5 - variable to assign read value (minutes)
 *  @param {unsigned char *} var_6 - variable to assign read value (seconds)
 *
 *  @return {0} - everything OK
 *  @return {-1} - problems via data reading from the INPUT:
 *  @throw if not 6 integers were read or some problems occured
 *  @throw if not 6 positive integers were produced (hh mm ss hh mm ss) or out
 *    of defined above ranges
 *
 *  @example
 *    char param_1 = 0;
 *    char param_2 = 0;
 *    char param_3 = 0;
 *    char param_4 = 0;
 *    char param_5 = 0;
 *    char param_6 = 0;
 *
 *    get_input_data(&param_1, &param_2, &param_3, &param_4, &param_5,
 *      &param_6) =>
 *    INPUT:
 *    12 45 16 4 23 48 => 0
 *    param_1{12} param_2{45} param_3{16}
 *    param_4{4} param_5{23} param_6{48}
 *
 *    get_input_data(&param_1, &param_2, &param_3, , &param_4, , &param_5,
 *      &param_6) =>
 *    INPUT:
 *    '\0' => -1
 *    param_1 = 0
 *    param_2 = 0
 *    param_3 = 0
 *    param_4 = 0
 *    param_5 = 0
 *    param_6 = 0
 *
 */
int get_input_data(unsigned char *var_1, unsigned char *var_2,
                   unsigned char *var_3, unsigned char *var_4,
                   unsigned char *var_5, unsigned char *var_6) {
  char temp_var_1 = 0;
  char temp_var_2 = 0;
  char temp_var_3 = 0;
  char temp_var_4 = 0;
  char temp_var_5 = 0;
  char temp_var_6 = 0;

  // get data that hh[0:23] mm[0:59] ss[0:59]
  if (scanf("%hhd %hhd %hhd %hhd %hhd %hhd", &temp_var_1, &temp_var_2,
            &temp_var_3, &temp_var_4, &temp_var_5, &temp_var_6) != 6) {
    puts("Error(get_input_data function): expected six space separated "
         "positive integers of type char like hh mm ss hh mm ss (24 hours "
         "format)");
    return -1;
  }

  // data validation
  if (validate_time_parts(temp_var_1, temp_var_2, temp_var_3, temp_var_4,
                          temp_var_5, temp_var_6) == 0) {
    puts("Error(get_input_data function): expected six space separated "
         "positive integers of type char like hh mm ss hh mm ss (24 hours "
         "format)");
    return -1;
  }

  // assigning data to the outer variables
  *var_1 = temp_var_1;
  *var_2 = temp_var_2;
  *var_3 = temp_var_3;
  *var_4 = temp_var_4;
  *var_5 = temp_var_5;
  *var_6 = temp_var_6;

  return 0;
}
