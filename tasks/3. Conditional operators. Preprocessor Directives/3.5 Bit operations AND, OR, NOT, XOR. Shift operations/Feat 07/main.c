/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191265/step/9?unit=1204235}
 *
 */

#include <stdio.h>

int main(void) {
  unsigned char bits;
  unsigned char res;
  unsigned char numToSwitchBits3And0 = 0b00001001;

  scanf("%hhu", &bits);

  res = bits ^ numToSwitchBits3And0;

  printf("%d", res);

  return 0;
}
