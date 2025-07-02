/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191284/step/9?unit=1204272}
 *
 */

#include <stdio.h>

int main(void) {
  unsigned int n;
  unsigned int m;
  unsigned int currNum;

  if (scanf("%u %u", &n, &m) != 2 || n >= m) {
    printf("expected two positive integers where first is less than second");

    return 0;
  }

  currNum = n;

  while (currNum <= m) {
    if (currNum % 3 == 0) {
      printf("%u ", currNum);
    }

    currNum += 1;
  }

  return 0;
}
