/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191281/step/9?unit=1204269}
 *
 */

#include <math.h>
#include <stdio.h>

#define MAX_LENGTH 100

int main(void) {
  unsigned short x;
  unsigned short y;
  double radiusVectorLength;

  if (scanf("%hu %hu", &x, &y) != 2) {
    printf("expected two postive integers");

    return 0;
  }

  radiusVectorLength = hypot((double)x, (double)y);

  if (radiusVectorLength > MAX_LENGTH) {
    printf("Radius length exceeds value of MAX_LENGTH");

    return 0;
  }

  printf("%.2f", radiusVectorLength);

  return 0;
}
