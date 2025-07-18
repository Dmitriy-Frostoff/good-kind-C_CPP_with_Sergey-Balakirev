/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191311/step/9?unit=1204299}
 *
 */

#include "./config.h"
#include "./utils.h"

int main(void) {
  int n;
  int m;
  int sum = 0;

  // get the @link{n} and @link{m} values
  if (get_natural_nums(&n, &m) != 0) {
    return 1;
  }

  // count @link{sum}
  sum = count_sum(n, m);

  // print @link{sum}
  printf("%d\n", sum);

  return 0;
}
