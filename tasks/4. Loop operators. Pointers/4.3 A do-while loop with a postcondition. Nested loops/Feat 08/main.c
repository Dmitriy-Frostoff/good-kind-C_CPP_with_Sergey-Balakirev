/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191286/step/10?unit=1204274}
 *
 */

#include <stdio.h>

int main(void) {
  unsigned short a;
  unsigned short b;

  if (scanf("%hu %hu", &a, &b) != 2 || a < 0 || b < 0 || a < 100 || a > 999 ||
      b < 100 || b > 999) {
    printf("expected two positive integers each in range [100; 999]");
    return 0;
  }

  for (unsigned short num = a; num <= b; num += 1) {
    unsigned short numCopy = num;
    unsigned char digitThous;
    unsigned char digitHund;
    unsigned char digitSimpl;

    // @example 123: 123 => 3, => 12
    digitSimpl = numCopy % 10;
    numCopy = numCopy / 10;

    // @example 123, 12 => 2, => 1
    digitHund = numCopy % 10;
    numCopy = numCopy / 10;

    // @example 123, 1 => 1, => 1
    digitThous = numCopy % 10;
    numCopy = numCopy / 10;

    if (digitSimpl != digitHund && digitSimpl != digitThous &&
        digitHund != digitThous) {
      printf("%d ", num);
    }
  }

  return 0;
}
