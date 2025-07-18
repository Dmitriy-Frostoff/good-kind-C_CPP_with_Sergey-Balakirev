/**
 *  The task description is at
 *  @link{https://stepik.org/lesson/1191312/step/7?unit=1204300}
 *
 */

#include "./config.h"
#include "./utils.h"

int main(void) {
  int start;
  int stop;
  int step;

  // get variables' values from the INPUT:
  if (get_variables_values(&start, &stop, &step) != 0) {
    return 1;
  }

  // print the coroutine values
  for (int i = 0; i < ITER_COUNT; i += 1) {
    printf("%d ", range(start, stop, step));
  }

  return 0;
}
