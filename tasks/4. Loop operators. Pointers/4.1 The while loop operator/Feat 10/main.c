/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191284/step/12?unit=1204272}
 *
 */

#include <stdio.h>

int main(void) {
  unsigned short a;
  unsigned short b;
  unsigned short minNum = 0;
  unsigned short maxNum = 0;

  if (scanf("%hu %hu", &a, &b) != 2 || a < 0 || b < 0) {
    printf("expected two positive integers like '123 435'");

    return 0;
  }

  minNum = a < b ? a : b;
  maxNum = a > b ? a : b;

  while (minNum > 0) {
    maxNum = maxNum % minNum;
    int minNumCopy = minNum;
    minNum = maxNum;
    maxNum = minNumCopy;
  }

  printf("%d", maxNum);

  return 0;
}
