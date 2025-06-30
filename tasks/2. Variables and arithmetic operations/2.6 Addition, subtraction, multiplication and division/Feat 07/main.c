/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191251/step/9?unit=1204222}
 *
 */

#include <stdio.h>

int main(void) {
  int a1;  // the first progression member
  int a50; // 50-th progression member
  int maxProgressionValue = 50;

  scanf("%d, %d", &a1, &a50);

  int progressionSum = ((double)a1 + (double)a50) / 2.0 * maxProgressionValue;
  printf("%d", progressionSum);

  return 0;
}
