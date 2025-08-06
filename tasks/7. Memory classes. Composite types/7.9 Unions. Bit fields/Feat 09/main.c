/**
 *  The task description is at
 *  @link{https://stepik.org/lesson/1191318/step/11?unit=1204306}
 *
 */

#include "./config.h"
#include "./utils.h"

int main(void) {
  PERSON_DATA pd = {};

  // set up @link{pd} fields
  pd.old = 45;
  pd.salary = 876043;
  pd.height = 186;
  pd.weight = 83;

  // print the size of bit field @link{pd}
  printf("%zu\n", sizeof(pd));

  /*
   *  макроопределение для тестирования (не убирать и должно
   *  идти непосредственно перед return 0)
   *
   */
  __ASSERT_TESTS__
  return 0;
}
