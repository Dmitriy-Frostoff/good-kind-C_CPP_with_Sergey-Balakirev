/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191290/step/10?unit=1204278}
 *
 */

#include <stdio.h>

int main(void) {
  unsigned char a;
  unsigned char b;
  unsigned char c;
  unsigned char d;

  if (scanf("%hhu %hhu %hhu %hhu", &a, &b, &c, &d) != 4 || a <= 0 || b <= 0 ||
      c <= 0 || d <= 0) {
    printf("expected 4 positive integers");
    return 0;
  }

  // a(or b) + 0.5 + 0.5 => a(or b) + 1
  // where
  //    a * b envelop dimensions
  //    0.5 and 0.5 required extra inner space
  //    (e.g. from the left and from the right sides)
  //    to nest postcard (c * d dimensions)
  /**
   * @example
   *    5 10 9 3 (a b c d) => (5 10) (9 3) => yes
   *    (5 - 0.5 - 0.5 >= 3) && (10 - 0.5 - 0.5 >= 9) => yes
   */
  if (((a - 1) >= c && (b - 1) >= d) || ((a - 1) >= d && (b - 1) >= c)) {
    printf("yes");
    return 0;
  }

  printf("no");

  return 0;
}
