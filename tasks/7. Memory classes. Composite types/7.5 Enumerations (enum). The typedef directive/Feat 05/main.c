/**
 *  The task description is at
 *  @link{https://stepik.org/lesson/1191314/step/7?unit=1204302}
 *
 *  Declare enum calc_types with constants: _perimetr=1, _square=2
 *
 *  Declare function 'calc_rect' with the next params (@note in order!):
 *    @type{double} width - rectangle width
 *    @type{double} height - rectangle height
 *    @type{enum calc_types} type - calculation type
 *
 *  The 'calc_rect' should return counted (@type{double}) rectangle's:
 *    square(if type is '_perimetr') or
 *    perimeter(if type is '_square')
 *
 *  In the 'main' function read from the INPUT: space separated:
 *  INPUT:
 *  type width height
 *
 *  Than call the 'calc_rect' function with read from the INPUT: arguments and
 *  print the result rounded to tenths to the console.
 *
 */

#include "./config.h"
#include "./utils.h"

int main(void) {
  enum calc_types type = _perimetr;
  double width = 0.0;
  double height = 0.0;
  double result = 0.0;

  // get the input data
  if (get_input_data(&type, &width, &height) != 0) {
    return 1;
  }

  // count perimeter or square
  result = calc_rect(width, height, type);

  // print result
  printf("%.1f", result);

  return 0;
}
