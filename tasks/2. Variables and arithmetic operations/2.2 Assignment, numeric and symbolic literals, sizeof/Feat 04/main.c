/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191244/step/6?unit=1204215}
 *
 * Declare two real variables of type 'double' with the names 'var_d1',
 * 'var_d2'. After that (with the next operator) assign them the value 0.5 along
 * the chain, using a construction of the form a = b = c = d
 *
 */

int main(void) {
  double var_d1;
  double var_d2;
  var_d1 = var_d2 = 0.5;
  /*
   * макроопределение для тестирования
   * (не убирать и должно идти непосредственно перед return 0)
   */
  __ASSERT_TESTS__
  return 0;
}
