/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191255/step/6?unit=1204226}
 *
 */

#include <stdio.h>

int main(void) {
  int firstNum;
  int secondNum;

  scanf("%d %d", &firstNum, &secondNum);

  firstNum *= 3;
  secondNum -= 10;
  int res = firstNum * secondNum;

  printf("%d", res);

  return 0;
}
