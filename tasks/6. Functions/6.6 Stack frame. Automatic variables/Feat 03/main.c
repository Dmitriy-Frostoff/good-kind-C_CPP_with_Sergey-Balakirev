/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191307/step/5?unit=1204295}
 *
 */

#include "./config.h"
#include "./utils.h"

int main(void) {
  double y;

  y = norm(RANGE_MIN, RANGE_MAX);

  /*
   * макроопределение для тестирования
   * (не убирать и должно идти непосредственно перед return 0)
   */
  __ASSERT_TESTS__
  return 0;
}
