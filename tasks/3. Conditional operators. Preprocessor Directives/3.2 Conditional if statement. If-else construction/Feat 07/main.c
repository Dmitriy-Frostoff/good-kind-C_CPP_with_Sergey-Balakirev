/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191260/step/9?unit=1204231}
 *
 */

#include <stdio.h>

int main(void) {
  unsigned int inputNum;

  if (scanf("%u", &inputNum) != 1) {
    printf("must be given one positive integer!");

    return 0;
  }

  if (inputNum % 10 == 3 || inputNum % 100 == 3 || inputNum % 1000 == 3 ||
      inputNum % 10000 == 3 || inputNum % 100000 == 3) {
    printf("yes");

    return 0;
  }

  printf("no");

  return 0;
}
