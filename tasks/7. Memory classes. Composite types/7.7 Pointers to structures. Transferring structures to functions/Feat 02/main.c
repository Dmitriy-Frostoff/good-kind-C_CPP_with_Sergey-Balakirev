/**
 *  The task description is at
 *  @link{https://stepik.org/lesson/1191316/step/4?unit=1204304}
 *
 */

#include "./config.h"
#include "./utils.h"

int main(void) {
  // initialize struct of @type{FIGURE}
  FIGURE geom = {.type = 1, .x0 = 10, .y0 = 20, .x1 = 50, .y1 = 30};
  // create pointer to the @link{geom}
  FIGURE *ptr_geom = &geom;

  // print @link{geom} data via @link{ptr_geom}
  printf("%hhd %d %d %d %d", ptr_geom->type, ptr_geom->x0, ptr_geom->y0,
         ptr_geom->x1, ptr_geom->y1);

  /*
   * макроопределение для тестирования
   * (не убирать и должно идти непосредственно перед return 0)
   */
  __ASSERT_TESTS__

  return 0;
}
