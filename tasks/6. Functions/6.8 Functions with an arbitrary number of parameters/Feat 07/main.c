/**
 *  The task description is at
 *  @link{https://stepik.org/lesson/1191309/step/9?unit=1204297}
 *
 *  Write 'ar_scan' variadic function with the next parameters (in
 *  order!):
 *  - pointer to the array of @type{double []}
 *  - quantity of nums to read from the array ( @type{size_t} )
 *  - variadic arguments ( @type{double*} )
 *
 *  The @callback{ar_scan} function reads consistently the numbers
 *  ( @type{double} ) from the array and assigns their values to the variadic
 *  variables (defined out of the function). Returns nothing ( @type{void}).
 *
 *  Call @callback{ar_scan} to read nums from the @link{weights} and assign
 *  their values to the variables (via got address in a variadic arguments).
 *
 *  No print to the console expected.
 *
 */

#include "./config.h"
#include "./utils.h"

int main(void) {
  double weights[ARR_SIZE] = {1.25, 4.34, -5.43, 0.01, -0.8};
  double w1;
  double w2;
  double w3;

  // assign nums from @link{weights} arr to variables
  ar_scan(weights, 3, &w1, &w2, &w3);

  printf("%.2f %.2f %.2f", w1, w2, w3);

  return 0;
}
