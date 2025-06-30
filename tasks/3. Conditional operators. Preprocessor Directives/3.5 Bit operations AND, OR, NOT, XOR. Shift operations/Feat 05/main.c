/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191265/step/7?unit=1204235}
 *
 */

#include <stdio.h>

int main(void) {
  unsigned char bits;
  unsigned char numToSwitchOffBits7And6 = 0b00111111;

  scanf("%hhu", &bits);

  printf("%d", bits & numToSwitchOffBits7And6);

  return 0;
}
