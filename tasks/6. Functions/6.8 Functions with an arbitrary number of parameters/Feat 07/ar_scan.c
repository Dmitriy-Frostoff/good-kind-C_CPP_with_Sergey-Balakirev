#include "./utils.h"

/**
 *  @brief Variadic function. Reads the @link{nums_read_quantity} nums from the
 *  array and assign their values to the variadic arguments (addresses of the
 *  outer variables)
 *
 *  @note ! Impure function! Mutates the outer variables (variadic, got) !
 *
 *  @param {const double []} arr - array of real numbers to read
 *  @param {size_t} nums_read_quantity - quantity of nums to read from the
 *    @link{arr}
 *  @param {*double} ... - variadic arguments. Address of the variables to
 *    assign read values of the @link{arr}
 *
 *  @example
 *    double var_1;
 *    double var_2;
 *    double var_3;
 *    double arr[20] = {1.25, 4.34, -5.43, 0.01, -0.8};
 *    ar_scan(arr, 3, &var_1, &var_2, &var_3) => void
 *      var_1{1.25}
 *      var_2{4.34}
 *      var_3{-5.43}
 */
void ar_scan(const double arr[], size_t nums_read_quantity, ...) {
  // setup the variadic arguments
  va_list arg;
  va_start(arg, nums_read_quantity);

  // read @link{arr} values and assign to the variadic variables
  for (size_t i = 0; i < nums_read_quantity; i += 1) {
    double *current_variable = va_arg(arg, double *);

    *current_variable = arr[i];
  }

  va_end(arg);
}
