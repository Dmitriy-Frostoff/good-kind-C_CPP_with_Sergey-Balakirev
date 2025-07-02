/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191287/step/10?unit=1204275}
 *
 */

#include <math.h>
#include <stdio.h>

int main(void) {
  unsigned short n;

  if (scanf("%hu", &n) != 1 || n <= 0) {
    printf("expected one natural number");
    return 0;
  }
  // every number / 1 => number => i start from 2
  // if there's no divider at range of n ^ 0.5 (rounded up) =>
  // no need to search further
  for (unsigned short i = 2; i < (unsigned short)ceil(sqrt(n)); i += 1) {
    if (n % i == 0) {
      printf("no");
      return 0;
    }
  }

  printf("yes");

  return 0;
}
