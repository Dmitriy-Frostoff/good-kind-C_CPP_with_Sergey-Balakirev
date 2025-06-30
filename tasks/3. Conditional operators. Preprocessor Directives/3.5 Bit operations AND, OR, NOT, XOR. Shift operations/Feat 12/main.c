/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191265/step/14?unit=1204235}
 *
 */

#include <stdio.h>

int main(void) {
  unsigned int flags;
  unsigned int mask;

  if (scanf("%u %u", &flags, &mask) != 2) {
    printf("expected two positive integers");
    return 0;
  }

  printf("%s", (flags ^ mask) != (flags | mask) ? "yes" : "no");

  return 0;
}
