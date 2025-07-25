/**
 *  The task description is at
 *  @link{https://stepik.org/lesson/1191315/step/5?unit=1204303}
 *
 *  Declare structure `struct` with identificator `tag_vector` and fields of
 *  integers `x, y, z` of @type{short}. In the `main` function declare variable
 *  of that type with name `vector`. Fill the `x, y, z` fields of that variable
 *  with the space separated data from the INPUT: in one line.
 *
 *  No OUTPUT: to the console expected.
 *
 */

#include "./config.h"
#include "./utils.h"

int main(void) {
  struct tag_vector vector = {};

  // get data from the INPUT:
  if (get_input_data(&vector.x, &vector.y, &vector.z) == -1) {
    return 1;
  }

  /*
   * макроопределение для тестирования
   * (не убирать и должно идти непосредственно перед return 0)
   */
  __ASSERT_TESTS__

  return 0;
}
