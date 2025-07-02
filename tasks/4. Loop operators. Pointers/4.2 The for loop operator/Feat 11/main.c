/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191285/step/13?unit=1204273}
 *
 */

#include <stdio.h>

int main(void) {
  unsigned int n;
  unsigned int leftPart;
  unsigned int rightPart;
  unsigned int leftSum = 0;
  unsigned int rightSum = 0;

  if (scanf("%u", &n) != 1 || (n < 100000 || n >= 1000000)) {
    printf("expected one six digit number");
    return 0;
  }

  // @example 123456 => 123
  leftPart = n / 1000;
  // @example 123456 => 456
  rightPart = n % 1000;

  for (unsigned short i = 0; i < 3; i += 1) {
    // @example 0 and 123 => 0 + 3 => 3 + 2 => 5 + 1
    leftSum += leftPart % 10;
    // @example 123 => 12 => 1
    leftPart = leftPart / 10;

    // @example 0 and 456 => 0 + 6 => 6 + 5 => 11 + 4
    rightSum += rightPart % 10;
    // @example 456 => 45 => 4
    rightPart = rightPart / 10;
  }

  printf("%s", leftSum == rightSum ? "yes" : "no");

  return 0;
}
