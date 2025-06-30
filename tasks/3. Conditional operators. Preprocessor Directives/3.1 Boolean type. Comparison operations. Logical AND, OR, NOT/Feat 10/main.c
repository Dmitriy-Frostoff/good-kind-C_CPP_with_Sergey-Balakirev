/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191258/step/12?unit=1204229}
 *
 */

#include <stdbool.h>
#include <stdio.h>

int main(void) {
  double inputNumX;
  double inputNumY;
  bool isNumXoutOfRange, isNumYoutOfRange;

  scanf("%lf %lf", &inputNumX, &inputNumY);

  isNumXoutOfRange = inputNumX < -5 || inputNumX > 10;
  isNumYoutOfRange = inputNumY < 0 || inputNumY > 7;

  printf("%d", isNumXoutOfRange || isNumYoutOfRange);

  return 0;
}
