/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191287/step/5?unit=1204275}
 *
 */

#include <stdio.h>

int main(void) {
  int mult = 1;
  int inputNum;

  while (scanf("%d", &inputNum) == 1 && inputNum != 0) {
    if (inputNum < 0) {
      continue;
    }

    mult *= inputNum;
  }

  printf("%d", mult);

  return 0;
}
