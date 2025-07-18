#include "./utils.h"

/**
 *  @brief Coroutine function. Generates integers at first call and returns
 *  @link{start} value.
 *
 *  At further calls returns increased by @link{step} value.
 *  At the moment when current value greater than @link{stop} reset current
 *  value to @link{start} and so on and so on infinite.
 *
 *  @param {int} start - generator begining value
 *  @param {int} stop - generator last value (including)
 *  @param {int} step - increasing step to get next value
 *
 *  @return {int} - current generator value in range
 *    [ @link{start} : @link{stop} ]
 *
 *  @example
 *    range(5, 11, 2) => 5
 *    range(5, 11, 2) => 7
 *    range(5, 11, 2) => 9
 *    range(5, 11, 2) => 11
 *    range(5, 11, 2) => 5
 *    etc infinite
 *
 */
int range(int start, int stop, int step) {
  static int start_base = 0;
  static int stop_base = 0;
  static int step_base = 0;

  // turn on coroutine params at first call
  if (start_base == 0 && stop_base == 0 && step_base == 0) {
    start_base += start;
    stop_base += stop;
    step_base += step;

    return start_base;
  }

  // set up settings for further calls
  start_base += step_base;

  // set up coroutine loop condition
  if (start_base > stop_base) {
    start_base = start;
    return start_base;
  }

  // return current value
  return start_base;
}
