/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191251/step/10?unit=1204222}
 *
 */

#include <math.h>
#include <stdio.h>

int main(void) {
  int b1;    // the first progression member
  int q;     // the denominator of the progression
  int n = 4; // quantity of progression members

  scanf("%d, %d", &b1, &q);

  int geomProgressionSum = (int)(pow(q, n) - 1) * b1 / (q - 1);
  printf("%d", geomProgressionSum);

  return 0;
}
