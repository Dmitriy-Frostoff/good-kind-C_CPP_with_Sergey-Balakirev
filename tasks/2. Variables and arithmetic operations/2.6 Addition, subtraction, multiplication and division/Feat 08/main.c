/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191251/step/10?unit=1204222}
 *
 */

#include <math.h>
#include <stdio.h>

int main(void) {
  int b1;    // первый член прогрессии
  int q;     // знаменатель прогрессии
  int n = 4; // кол-во членов прогрессии

  scanf("%d, %d", &b1, &q);

  int geomProgressionSum = (int)(pow(q, n) - 1) * b1 / (q - 1);
  printf("%d", geomProgressionSum);

  return 0;
}
