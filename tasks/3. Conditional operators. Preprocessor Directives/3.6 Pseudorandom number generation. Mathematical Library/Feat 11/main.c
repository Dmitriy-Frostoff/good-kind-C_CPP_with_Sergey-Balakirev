/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191266/step/13?unit=1204237}
 *
 */

#include <math.h>
#include <stdio.h>

int main(void) {
  unsigned short N;
  double inchToCm = 2.54;

  if (scanf("%hu", &N) != 1) {
    printf("Expected one positive integer!");

    return 0;
  }

  printf("%u", (int)round(inchToCm * N));

  return 0;
}
