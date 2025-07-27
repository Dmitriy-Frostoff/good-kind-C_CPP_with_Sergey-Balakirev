/**
 *  The task description is at
 *  @link{https://stepik.org/lesson/1191315/step/9?unit=1204303}
 *
 */

#include "./config.h"
#include "./utils.h"

int main(void) {
  struct tag_time tm1 = {};
  struct tag_time tm2 = {};

  // get time data with validation
  get_input_data(&tm1.hours, &tm1.minutes, &tm1.seconds, &tm2.hours,
                 &tm2.minutes, &tm2.seconds);

  struct tag_time tm_sum = {};

  // fill @link{tm_sum}
  // TODO! refactor to external function like
  // fill_time_struct(unsigned char
  //  tm1.hours, unsigned char tm1.minutes, unsigned char tm1.seconds, unsigned
  //  char tm2.hours, unsigned char tm2.minutes, unsigned char tm2.seconds)
  tm_sum.seconds = (tm1.seconds + tm2.seconds) % SECONDS;
  // add minutes if minutes sum >= 60
  tm_sum.minutes += (tm1.seconds + tm2.seconds) / SECONDS;
  tm_sum.minutes += (tm1.minutes + tm2.minutes) % MINUTES;
  // add hours if minutes sum >= 60
  tm_sum.hours += (tm1.minutes + tm2.minutes) / MINUTES;
  tm_sum.hours += (tm1.hours + tm2.hours) % HOURS;

  // print @link{tm_sum} result data
  printf("%02hhu:%02hhu:%02hhu\n", tm_sum.hours, tm_sum.minutes,
         tm_sum.seconds);

  /*
   * макроопределение для тестирования
   * (не убирать и должно идти непосредственно перед return 0)
   */
  __ASSERT_TESTS__
  return 0;
}
