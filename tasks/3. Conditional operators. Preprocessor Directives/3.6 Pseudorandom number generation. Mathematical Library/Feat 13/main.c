/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191266/step/15?unit=1204237}
 *
 */

#include <math.h>
#include <stdio.h>

int main(void) {
  int a;
  int b;
  double tan;
  double angleInRad;

  if (scanf("%d, %d", &a, &b) != 2) {
    printf("expected two positive integers!");

    return 0;
  }

  tan = (double)a / (double)b;

  angleInRad = atan(tan);

  printf("%.2f %.2f", tan, angleInRad);

  return 0;
}
