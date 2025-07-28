/**
 *  The task description is at
 *  @link{https://stepik.org/lesson/1191316/step/8?unit=1204304}
 *
 */

#include "./config.h"
#include "./utils.h"

int main(void) {
  COMPLEX cmp_1 = {};
  COMPLEX cmp_2 = {};
  COMPLEX res = {};
  // get real and imaginary parts for @link{cmp_1} and @link{cmp_2}
  get_input_data(&cmp_1, &cmp_2);

  // count sum of @link{cmp_1} and @link{cmp_2}
  res = complex_sum(cmp_1, cmp_2);

  /*
   * макроопределение для тестирования
   * (не убирать и должно идти непосредственно перед return 0)
   */
  __ASSERT_TESTS__

  return 0;
}
