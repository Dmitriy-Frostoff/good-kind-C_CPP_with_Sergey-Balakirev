/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191249/step/9?unit=1204220}
 *
 */
#include <stdio.h>

int main(void) {
  int num_1;
  int num_2;
  float num_3;

  scanf("%d, %d, %*f, %f", &num_1, &num_2, &num_3);
  printf("%d %d %.2f", num_1, num_2, num_3);

  return 0;
}
