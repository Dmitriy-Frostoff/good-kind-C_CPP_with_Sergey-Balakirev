/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191247/step/12?unit=1204218}
 *
 * The program should use the printf() function to output the current time
 * stored in variables: h - hours; m - minutes; s - seconds in hexadecimal
 * format with the prefix 0x output.:
 *
 * 0xhh:0xmm:0xss
 *
 * For example, for h = 12, m = 3, s = 9 it should be:
 *
 * 0x0c:0x03:0x09
 *
 * (note the insignificant zero if the number is less than 16).
 *
 */
#include <stdio.h>

int main(void) {
  unsigned char h = 17;
  unsigned char m = 45;
  unsigned char s = 5;

  printf("%#0.2x:%#0.2x:%#0.2x", h, m, s);

  return 0;
}
