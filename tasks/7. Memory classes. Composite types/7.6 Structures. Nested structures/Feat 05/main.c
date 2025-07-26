/**
 *  The task description is at
 *  @link{https://stepik.org/lesson/1191315/step/7?unit=1204303}
 *
 *  There's declared structure `tag_price` and variable `price_100` of that
 *  type. In the `main` function decalre variable `pr` of type `tag_price`and
 *  thant copy data from the `price_100` to the `pr`. Than print to the console
 *  all the fileds data from the 'pr' in order of `tag_price` declaration. All
 *  the fields except `name` must be decimal numbers.
 *
 */

#include "./config.h"
#include "./utils.h"

int main(void) {
  struct tag_price pr = {};
  // copy all the data from @link{price_100} to the @link{pr}
  pr = price_100;

  // print all the data of @link{pr}
  printf("%s %u %u %u", pr.name, pr.rubs, pr.kops, pr.foreign_key);

  /*
   * макроопределение для тестирования
   * (не убирать и должно идти непосредственно перед return 0)
   */
  __ASSERT_TESTS__

  return 0;
}
