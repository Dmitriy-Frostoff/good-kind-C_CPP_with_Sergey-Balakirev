/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191258/step/9?unit=1204229}
 *
 */

#include <stdio.h>

int main(void) {
  int rangeMinValue = -545;
  int rangeMaxValue = 1037;

  double inputNum;

  scanf("%lf", &inputNum);
  inputNum = (int)(inputNum * 100);

  printf("%d", inputNum >= rangeMinValue && inputNum <= rangeMaxValue);

  return 0;
}
