/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191258/step/10?unit=1204229}
 *
 */

#include <stdio.h>

int main(void) {
  double inputNum;

  scanf("%lf", &inputNum);

  printf("%d",
         (inputNum >= -10 && inputNum < 0) || (inputNum > 5 && inputNum <= 12));

  return 0;
}
