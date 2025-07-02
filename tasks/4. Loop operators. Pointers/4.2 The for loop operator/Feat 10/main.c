/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191285/step/12?unit=1204273}
 *
 */

#include <stdio.h>

int main(void) {
  unsigned short numInput;
  unsigned short numMutable;
  unsigned short currDigit;

  if (scanf("%hu", &numInput) != 1 || numInput < 0) {
    printf("expected one positive integer");
    return 0;
  }

  if (numInput < 10) {
    printf("%hu", numInput);
    return 0;
  }

  numMutable = numInput;

  while (numMutable != 0) {
    // @example 4235 => 5, 423 => 3
    currDigit = numMutable % 10;

    printf("%u", currDigit);

    /**
     * @example
     * 4235 => 423
     * 423 => 42
     * 42 => 4
     */
    numMutable = numMutable / 10;
  }

  return 0;
}
