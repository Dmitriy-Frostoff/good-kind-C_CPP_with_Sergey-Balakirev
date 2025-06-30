/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191266/step/12?unit=1204237}
 *
 */

#include <math.h>
#include <stdio.h>

int main(void) {
  unsigned short N;
  unsigned short entireTeaBags;
  unsigned short res;
  unsigned short bagsAtTeaPack = 100;

  if (scanf("%hu", &N) != 1) {
    printf("expected positive integer");

    return 0;
  }

  entireTeaBags = 7 * N;
  res = ceil((double)entireTeaBags / (double)bagsAtTeaPack);

  printf("%u", res);

  return 0;
}
