/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191265/step/5?unit=1204235}
 *
 */

#include <stdio.h>

int main(void) {
  unsigned char b;
  unsigned char not_b;

  scanf("%hhu", &b);

  not_b = ~b;

  printf("%d", not_b);

  return 0;
}
