/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191258/step/11?unit=1204229}
 *
 */

#include <stdbool.h>
#include <stdio.h>

int main(void) {
  double inputNumX;
  double inputNumY;
  bool isInXrange, isInYRange;

  scanf("%lf %lf", &inputNumX, &inputNumY);

  isInXrange = inputNumX >= -5 && inputNumX <= 10;
  isInYRange = inputNumY >= 0 && inputNumY <= 7;

  printf("%d", isInXrange && isInYRange);

  return 0;
}
