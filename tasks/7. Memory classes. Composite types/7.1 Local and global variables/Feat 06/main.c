/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191310/step/8?unit=1204298}
 *
 */

#include "./config.h"

int is_positive(int num);

int main(void) {
  int x;

  // get integers from the INPUT: and print non-negative ones
  while (scanf("%d", &x) == 1) {
    if (is_positive(x)) {
      printf("%d ", x);
    }
  }

  return 0;
}
