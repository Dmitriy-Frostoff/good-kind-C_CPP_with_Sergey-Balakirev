#include "./utils.h"
#include "config.h"

/**
 *  @brief Count the normal vector for two - axis (or three, or four) system
 *  @note !Expected low case value of @link{str}!
 *
 *  expected the next types of choice axis system:
 *    "vector2" for two - axis (2 real number coordinates)
 *    "vector3" for three - axis (3 real number coordinates)
 *    "vector4" for four - axis (4 real number coordinates)
 *    if non of that so will be got 0.0 as return value
 *
 *  'normal vector' value is counted in a next way (e.g. for "vector2")
 *  'normal vector' = x ** 2 + y ** 2,
 *    where 'x' and 'y' are coordinates
 *
 *  @param {const char *} str - low case string with one of the predefined
 *    values
 *  @param {double} ... - real numbers based on @link{str} value (@see scheme
 *    above)
 *
 *  @return {double} - counted 'normal vector' value (rounded to tenths)
 *
 *  @example
 *    v_norm2("vector2", 1.0, 2.0) => 5.0
 *    v_norm2("vector3", 1.0, 2.0, 3.0) => 14.0
 *    v_norm2("vector4", 1.0, -2.0, 3.0, -4.0) => 30.0
 *
 */
double v_norm2(const char *str, ...) {
  double res = 0.0;
  int axis_value = 0;

  // is two dimension axis?
  if (strcmp(str, TWO_AXIS_LABEL) == 0) {
    axis_value = TWO_AXIS_DIM_COUNT;
  }

  // is three dimension axis?
  if (strcmp(str, THREE_AXIS_LABEL) == 0) {
    axis_value = THREE_AXIS_DIM_COUNT;
  }

  // is four dimension axis?
  if (strcmp(str, FOUR_AXIS_LABEL) == 0) {
    axis_value = FOUR_AXIS_DIM_COUNT;
  }

  // not one of the predefined string axis - values ? => return 0.0
  if (axis_value == 0) {
    return 0.0;
  }

  // setup variadic params
  va_list arg;
  va_start(arg, str);

  // count normal vector
  for (int i = 0; i < axis_value; i += 1) {
    res += pow(va_arg(arg, double), 2);
  }

  va_end(arg);

  return res;
}
