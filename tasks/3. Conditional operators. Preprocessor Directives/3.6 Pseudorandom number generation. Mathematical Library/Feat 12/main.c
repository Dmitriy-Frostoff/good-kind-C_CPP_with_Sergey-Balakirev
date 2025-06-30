/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191266/step/14?unit=1204237}
 *
 */

#include <math.h>
#include <stdio.h>

int main(void) {
  double angleInDeg;
  double sinOfAngle;
  double PI = 3.1415;

  if (scanf("%lf", &angleInDeg) != 1) {
    printf("Expected positive real number!");

    return 0;
  }

  angleInDeg = angleInDeg * PI / 180.0;

  sinOfAngle = sin(angleInDeg);

  printf("%.1f", sinOfAngle);

  return 0;
}
