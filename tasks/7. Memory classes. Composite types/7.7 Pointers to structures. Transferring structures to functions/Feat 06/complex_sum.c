#include "./utils.h"

/**
 *  @brief Count sum of two structures of @type{COMPLEX} and return result sum
 *  structure
 *
 *  @note ! Impure function !
 *  - implicit dependency on type @link{COMPLEX}
 *
 *  Count sum of two complex numbers via formula:
 *  a + i * b = (a1 + a2) + i * (b1 + b2),
 *  where `a` is a real part and `b` is an imaginary part of a complex number
 *  `i` is imaginary unit (in this realization it's omitted, but better to use
 *  <complex.h> library for that case with `I`)
 *
 *  @param {COMPLEX} obj_1 - first structure to count sum
 *  @param {COMPLEX} obj_2 - second structure to count sum
 *
 *  @return {COMPLEX} - result sum structure
 *
 *  @example
 *    COMPLEX obj_1 = {.re = 6.0, .im = 10.0}
 *    COMPLEX obj_2 = {.re = 3.0, .im = 6.0}
 *    COMPLEX res = {};
 *
 *    res = complex_sum(obj_1, obj_2);
 *    res = {re = 9.0; im = 16.0}
 *
 */
COMPLEX complex_sum(COMPLEX obj_1, COMPLEX obj_2) {
  COMPLEX res_obj = {0};

  res_obj.re = obj_1.re + obj_2.re;
  res_obj.im = obj_1.im + obj_2.im;

  return res_obj;
}
