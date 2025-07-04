/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191306/step/4?unit=1204294}
 *
 */

#include "./config.h"
#include "./utils.h"

int main(void) {
  double a;
  double b;

  double (*ptr_max_2)(double, double) = NULL;

  // set pointer to the max_2 function
  ptr_max_2 = max_2;

  // get two comma separated real numbers
  get_two_real_numbers(&a, &b);

  // get the max of two real numbers and print it to the terminal
  printf("%.1f\n", ptr_max_2(a, b));

  /*
   * макроопределение для тестирования
   * (не убирать и должно идти непосредственно перед return 0)
   */
  __ASSERT_TESTS__
  return 0;
}
