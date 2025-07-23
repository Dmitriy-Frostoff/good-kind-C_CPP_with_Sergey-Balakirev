#include "./utils.h"

/**
 *  @brief Count perimeter or square of the rectangle
 *
 *  @note ! Impure function! Depends on global @link{enum calc_types} !
 *
 *  @param {double} width - the rectangle width
 *  @param {double} height - the rectangle height
 *  @param {enum calc_types} type - type of the operation:
 *    1 - count perimeter
 *    2 - count square
 *
 *  @return {double} - counted perimeter or square or just 0.0 if type
 *    is not 1 or 2
 *  @return {-1.0} - if @link{width} or @link{height} are not positive
 *  @throw if @link{width} or @link{height} are not positive
 *
 *  @example
 *      calc_rect(3.5, 7.8, 1) => 22.600000
 *      calc_rect(-3.5, 7.8, 1) => -1.0
 *      calc_rect(3.5, 7.8, 10) => 0
 *
 */
double calc_rect(double width, double height, enum calc_types type) {
  if (width <= 0 || height <= 0) {
    return -1.0;
  }

  double result = 0.0;

  switch (type) {
  case _perimetr:
    result = 2 * (width + height);
    break;
  case _square:
    result = width * height;
    break;
  default:
    break;
  }

  return result;
}
