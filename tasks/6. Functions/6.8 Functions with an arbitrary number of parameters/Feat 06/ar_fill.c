#include "./utils.h"

/**
 *  @brief Fill the @link{arr} with variadic @link{nums_quantity} nums of
 *  @type{double}
 *
 *  @note ! Impure function! Mutates the original @link{arr} !
 *
 *  @param {double []} arr - empty array of real numbers to fill
 *  @param {size_t} nums_quantity - quantity of nums to fill (strongly required
 *    for varidic funtion!)
 *  @param {double} ... - variadic quantity of nums to nest to the @link{arr}
 *
 *  @example
 *    double arr[20] = {0};
 *    ar_fill(weights, 5, 0.1, 0.2, 0.3, 0.4, 0.5) => void
 *      arr{0.1, 0.2, 0.3, 0.4, 0.5}
 *
 */
void ar_fill(double arr[], size_t nums_quantity, ...) {
  // setup variadic arguments
  va_list arg;
  va_start(arg, nums_quantity);

  // fill @link{arr} with nums @type{double}
  for (size_t i = 0; i < nums_quantity; i += 1) {
    double current_num = va_arg(arg, double);

    arr[i] = current_num;
  }

  va_end(arg);
}
