#include "./utils.h"

/**
 *  @brief Count sum of variadic args based on etalon string (sum only if char
 *  in the @link{format} is '+')
 *
 *  Function with variadic arguments that sum every arg if
 *  correspondent char in the @link{format} string (given as first param of
 *  @callback{sumf}) is '+'.
 *              indexes 012345   0  1  2  3  4  5
 *  I.e. logic is sumf("++ + +", 1, 2, 3, 4, 5, 6) => 1 + 2 + 4 + 6 => 13
 *
 *  @param {const char *} format - etalon string that consist of '+' and ' '
 *  @param {double} ... - real numbers to sum if condition is true
 *
 *  @return {double} - counted sum of variadic args
 *
 *  @example
 *    indexes 012345   0  1  2  3  4  5
 *      sumf("++ + +", 1, 2, 3, 4, 5, 6) => 1 + 2 + 4 + 6 => 13
 */
double sumf(const char *format, ...) {
  double sum = 0;
  size_t str_index = 0;

  // setup variadic params
  va_list arg;
  va_start(arg, format);

  while (*(format + str_index) != '\0') {
    // get current num
    double current_num = va_arg(arg, double);

    // get sum if condition true
    if (*(format + str_index) == '+') {
      sum += current_num;
    }

    str_index += 1;
  }

  va_end(arg);

  return sum;
}
