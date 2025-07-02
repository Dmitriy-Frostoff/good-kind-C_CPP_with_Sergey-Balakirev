/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191287/step/7?unit=1204275}
 *
 */

#include <stdio.h>

int main(void) {
  unsigned short divider = 2;
  unsigned short n;
  unsigned short nCopy;

  if (scanf("%hu", &n) != 1 || n <= 0) {
    printf("expected one natural number");
    return 0;
  }

  // 1 is divisible only by itself
  if (n == 1) {
    printf("%hu", n);
    return 0;
  }

  // prevent mutation of n
  nCopy = n;

// goto to start for cycle from the begining (from the divider = 2)
/**
 * @example
 *    nCopy = n = 5
 *    nCopy 5, divider 2 => 5 % 2 (3...4...) != 0
 *    5 % 5 == 0 => nCopy = 1, divider = 2
 *    begin again => divider <= nCopy ? no => end
 */
start:
  for (divider; divider <= nCopy; divider += 1) {
    if (nCopy % divider == 0) {
      printf("%u ", divider);

      nCopy /= divider;
      divider = 2;
      goto start;
    }
  }

  return 0;
}
