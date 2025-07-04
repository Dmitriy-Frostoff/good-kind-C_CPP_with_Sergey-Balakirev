/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191306/step/9?unit=1204294}
 *
 */
#include "./config.h"
#include "./utils.h"

int main(void) {
  int num_1;
  int num_2;
  int num_3;
  int num_4;
  int sum = 0;

  // get 4 integers from the INPUT
  get_integers(&num_1, &num_2, &num_3, &num_4);

  // get the sum of two biggest integers
  sum = sum_big2(num_1, num_2, num_3, num_4);

  printf("%d\n", sum);

  return 0;
}
