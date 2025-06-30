/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191262/step/4?unit=1204233}
 *
 */

#include <stdio.h>

int main(void) {
  int k;
  int m;

  if (scanf("%d, %d", &k, &m) != 2) {
    printf("Input error.");
    return 0;
  }

  printf("%d", k < m ? k * k : m * m);

  return 0;
}
