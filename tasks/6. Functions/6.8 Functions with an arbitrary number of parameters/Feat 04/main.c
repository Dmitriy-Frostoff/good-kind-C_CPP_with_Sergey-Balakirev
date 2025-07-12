/**
 *  The task description is at
 *  @link{https://stepik.org/lesson/1191309/step/5?unit=1204297}
 *
 *  Write function @callback{v_norm2} that count normal vector of the arbitrary
 *  got integers and where first param is the string.
 *  Possible string values:
 *    "vector2" (two dimensions vector)
 *    "vector3" (three dimensions vector)
 *    "vector4" (four dimensions vector)
 *    or just retrun 0.0 for any other string values
 *
 *  For two dimensions vector normal vector is 'x ** 2 + y ** 2',
 *  where 'x' and 'y' are variadic params
 *
 *  Print the counted value to the console with precision to tenths.
 *
 */

#include "./config.h"
#include "./utils.h"

int main(void) {
  double res = 0;

  // get the str (choice of axis count)
  char str_axis_value[] = TWO_AXIS_LABEL;
  // low case choice string
  str_to_low(str_axis_value);

  // count mean of the integers
  res = v_norm2(str_axis_value, 1.0, 2.0);

  printf("\t%.1f\n", res);

  return 0;
}
