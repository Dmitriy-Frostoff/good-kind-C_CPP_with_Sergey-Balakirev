/**
 *  The task description is at
 *  @link{https://stepik.org/lesson/1191313/step/6?unit=1204301}
 *
 *  Declare pointer with name `data` of @type{short}. Allocate from the `heap`
 *  for elemets of @type{short}. Than via pointer `data` nest to the allocated
 *  memory area the values: -4, 3, 0, 100.
 *
 *  The `data` pointer must stay immutable (should still refer to the start of
 *  allocated  memory area).
 *
 *  No OUTPUT: data expected. free() allocated memory at the end of main()
 *  program (right after `__ASSERT_TESTS__`)
 *
 */

#include "./config.h"
#include "./utils.h"

int main(void) {
  // allocate memory area
  short *data = malloc(4 * sizeof(short));

  // nest to the allocated memory values: -4, 3, 0, 100
  data[0] = -4;
  data[1] = 3;
  data[2] = 0;
  data[3] = 100;

  /*
   * макроопределение для тестирования (не убирать)
   */
  __ASSERT_TESTS__;

  // free allocated memory
  free(data);

  return 0;
}
