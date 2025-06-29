/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191251/step/11?unit=1204222}
 *
 */

#include <stdio.h>

int main(void) {
  unsigned char a;

  scanf("%hhu", &a);

  double res = 1.732 * a / 6.0;
  printf("%.3f", res);

  return 0;
}
