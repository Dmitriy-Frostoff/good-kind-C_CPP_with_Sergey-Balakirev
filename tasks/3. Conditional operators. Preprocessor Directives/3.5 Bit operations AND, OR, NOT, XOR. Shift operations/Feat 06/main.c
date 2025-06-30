/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191265/step/8?unit=1204235}
 *
 */

#include <stdio.h>

int main(void) {
  unsigned char bits;
  unsigned char res;
  unsigned char numToSwitchOnBits4And2And0 = 0b00010101;

  scanf("%hhu", &bits);

  res = bits | numToSwitchOnBits4And2And0;

  printf("%d", res);

  return 0;
}
