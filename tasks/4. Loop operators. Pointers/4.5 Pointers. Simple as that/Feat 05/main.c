/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191288/step/7?unit=1204276}
 *
 * Decalre pointer 'ptr_var_d' to work with 'var_d' variable. Via 'ptr_var_d'
 * set 'var_d' value to -54.38
 *
 */

#include <stdio.h>

int main(void) {
  double var_d = 0;

  double *ptr_var_d = &var_d;
  *ptr_var_d = -54.38;

  /**
   * макроопределение для тестирования
   * (не убирать и должно идти непосредственно перед return 0)
   */
  __ASSERT_TESTS__
  return 0;
}
