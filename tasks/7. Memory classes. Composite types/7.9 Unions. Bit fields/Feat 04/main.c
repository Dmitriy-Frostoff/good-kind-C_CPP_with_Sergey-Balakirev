/**
 *  The task description is at
 *  @link{https://stepik.org/lesson/1191318/step/6?unit=1204306}
 *
 */

#include "./config.h"
#include "./utils.h"

int main(void) {
  POINT2 pt;

  // get data from the INPUT:
  if (get_input_data(&pt) != 0) {
    return 1;
  }

  /*
   * макроопределение для тестирования
   * (не убирать и должно идти непосредственно перед return 0)
   */
  __ASSERT_TESTS__

  return 0;
}
