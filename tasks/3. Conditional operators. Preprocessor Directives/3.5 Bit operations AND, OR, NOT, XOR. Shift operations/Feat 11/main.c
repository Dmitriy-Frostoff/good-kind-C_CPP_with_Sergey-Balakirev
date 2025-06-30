/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191265/step/13?unit=1204235}
 *
 */

#include <stdio.h>

int main(void) {
  unsigned short flags;
  unsigned short mask;

  if (scanf("%hu %hu", &flags, &mask) != 2) {
    printf("expected two positive integers");

    return 0;
  }

  if ((flags & mask) == mask) {
    printf("yes");
  } else {
    printf("no");
  }

  return 0;
}
