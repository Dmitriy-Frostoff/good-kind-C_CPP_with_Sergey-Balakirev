/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191284/step/11?unit=1204272}
 *
 */

#include <math.h>
#include <stdio.h>

int main(void) {
  unsigned int num;
  unsigned short digitCount = 0;
  unsigned short i = 0;
  unsigned short j = 1;

  if (scanf("%u", &num) != 1 || num <= 0) {
    printf("expected one positive integer");

    return 0;
  }

  // get the max count of digits in the num
  // @example 1221 => 4
  while ((num / (int)pow(10, digitCount)) > 0) {
    digitCount += 1;
  }

  // variable to prevent mutation of the digitCount
  // use to count new (reduced) num digits length
  // @example 1221 => 4; 22 => 2;
  i = digitCount;

  while (j < i) {
    // check that both integers from the left and from the right are equal
    /**
     * @example
     * 1221 / (int)pow(10, (4 - 1)) => 1 (first one)
     * 1221 % 10 => 1 (last one)
     */
    if (num / (int)pow(10, (i - 1)) != num % 10) {
      printf("no");

      return 0;
    }

    // @example 1221 => 122
    num = num % (int)pow(10, digitCount - j);

    // @example 122 => 22
    num = num / 10;

    // increase digits of a number counter by 1
    j += 1;

    // num digits length decreased by two (see above actions with num)
    i -= 2;
  }

  printf("yes");

  return 0;
}
