/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191307/step/7?unit=1204295}
 *
 */

#include "./config.h"
#include "./utils.h"

int main(void) {
  short digs[MAX_SIZE];
  size_t digs_length = sizeof(digs) / sizeof(*digs);
  int count = 0;

  // fill the @link{digs} from the INPUT
  count = fill_arr(digs, digs_length);

  // revert the @link{count} elems of @link{digs}
  reverse(digs, count);

  // print first @link{count} nums of @link{arr}
  print_first_N_nums(digs, count);

  return 0;
}
