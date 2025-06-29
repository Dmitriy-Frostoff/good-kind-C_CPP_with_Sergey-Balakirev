/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191244/step/13?unit=1204215}
 *
 * Declare a real variable of type 'double'. Use the 'sizeof' operation to
 * calculate the size that this variable occupies in the device memory. Save the
 * result in the integer variable 'res'.
 *
 */
int main(void) {
  double test_var;
  int res = sizeof(test_var);
  /*
   * макроопределение для тестирования
   * (не убирать и должно идти непосредственно перед return 0)
   */
  __ASSERT_TESTS__
  return 0;
}
