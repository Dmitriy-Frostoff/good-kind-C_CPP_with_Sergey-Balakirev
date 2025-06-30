/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191265/step/6?unit=1204235}
 *
 */

#include <stdio.h>

int main(void) {
  unsigned char bits;
  unsigned char maskWithBitsOn3And5 = 40;

  scanf("%hhu", &bits);

  if ((bits & maskWithBitsOn3And5) == maskWithBitsOn3And5) {
    printf("%d", bits);
  } else {
    printf("%d", -1);
  }

  return 0;
}
