/**
 *  The task description is at
 *  @link{https://stepik.org/lesson/1191309/step/7?unit=1204297}
 *
 *  Write 'ar_fill' variadic function with the next parameters (in
 *  order!):
 *  - pointer to the array of @type{double}
 *  - quantity of nums to nest to the array ( @type{size_t} )
 *  - with variadic arguments ( @type{double} )
 *
 *  The @callback{ar_fill} function nests variadic params of predefined above
 *  quantity to the array and return nothing ( @type{void}).
 *
 *  Call @callback{ar_fill} to fill the @link{weights} array with the numbers:
 *  0.1, 0.2, 0.3, 0.4, 0.5
 *
 *  No print to the console expected.
 *
 */

#include "./config.h"
#include "./utils.h"

int main(void) {
  double weights[ARR_SIZE] = {0};

  ar_fill(weights, 5, 0.1, 0.2, 0.3, 0.4, 0.5);

  return 0;
}
