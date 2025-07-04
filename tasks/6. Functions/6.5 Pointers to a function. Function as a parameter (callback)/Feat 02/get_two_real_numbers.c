#include "./utils.h"

/**
 *  @brief Get the two comma separated real numbers from the input
 *  @note !Impure function! Modifies given arguments via their pointers
 *
 *  @param {double *} num_a - pointer to the variable
 *  @param {double *} num_b - pointer to the variable
 *
 *  @return {int} - 0, everything is OK
 *  @throw if pointers are NULL or not two comma separated real numbers were
 *    produced and return exit code 1
 *
 *  @example
 *    double a, double b;
 *    get_two_real_numbers(&a, &b) =>
 *    INPUT:
 *    5.0 2.6
 *    => 0
 *    a = 5.0, b = 2.6
 */
int get_two_real_numbers(double *ptr_num_a, double *ptr_num_b) {
  if (ptr_num_a == NULL || ptr_num_b == NULL) {
    puts("Error: pointers are NULL");
    return 1;
  }

  if (scanf("%lf, %lf", ptr_num_a, ptr_num_b) != 2) {
    puts("Error: incorrect input. Expected two comma separated real numbers");
    return 1;
  }
  return 0;
}
