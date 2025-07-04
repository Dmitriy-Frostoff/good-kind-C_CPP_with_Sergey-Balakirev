#include "./utils.h"

/**
 *  @brief Get max of two real numbers
 *
 *  @param {double} a - real number
 *  @param {double} b - real number
 *
 *  @return {double} - max of given arguments
 *
 *  @example
 *    max_2(5.0, -2.0) => 5.0
 */
double max_2(double a, double b) {
  return (a > b) ? a : b;
}
