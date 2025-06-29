/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191247/step/11?unit=1204218}
 *
 * The program should use the printf() function to output the current time
 * stored in the variables: h - hours; m - minutes; s - seconds in the format:
 * hh:mm:ss
 *
 * For example, for h = 12, m = 3, s = 9 it should be:
 * 12:03:09
 * (note the insignificant zero if the number is less than 10).
 *
 */
#include <stdio.h>

int main(void) {
  unsigned char h = 11;
  unsigned char m = 8;
  unsigned char s = 1;

  printf("%0.2u:%0.2u:%0.2u", h, m, s);

  return 0;
}
