#include "./utils.h"

/**
 *  @brief Coroutine function that returns integers starting from
 *    @link{COROUTINE_BASE_NUM} (currently 5) and than with step
 *    @link{COROUTINE_STEP_NUM} (currently 3)
 *
 *  @note ! Impure function ! Depends on macros @link{COROUTINE_BASE_NUM} and
 *    @link{COROUTINE_STEP_NUM} !
 *
 *  @return {int} - integers starting from @link{COROUTINE_BASE_NUM} and than
 *    with step @link{COROUTINE_STEP_NUM}
 *
 *  @example
 *    COROUTINE_BASE_NUM 5
 *    COROUTINE_STEP_NUM 3
 *    range() => 5
 *    range() => 8
 *    range() => 11
 *    range() => 14
 *    range() => 17
 *    ...
 *    and further calls till the main() termination
 *
 */
int range(void) {
  // static are only initialized at first call of the @callback{range} and
  // over the further calls save their values (and can be modified)
  static int base_num_part = COROUTINE_BASE_NUM;
  static int step = 0;

  // update values over the further calls
  base_num_part = base_num_part + step;
  step = COROUTINE_STEP_NUM;

  // return current counted value
  return base_num_part;
}
