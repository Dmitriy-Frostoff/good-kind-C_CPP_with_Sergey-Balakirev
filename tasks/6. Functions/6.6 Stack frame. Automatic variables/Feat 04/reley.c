#include "./utils.h"

/**
 *  @brief Count sqrt(x1**2 + x2**2)
 *
 *  @param {double} x1 - real number
 *  @param {double} x2 - real number
 *
 *  @return {double} - counted result
 *
 *  @example
 *    reley(-3.68, 4.14) => 5.539134
 */
double reley(double x1, double x2) {
  double res = hypot(x1, x2);
  return res;
}
