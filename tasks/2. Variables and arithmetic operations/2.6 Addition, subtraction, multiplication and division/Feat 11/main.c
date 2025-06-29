/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191251/step/13?unit=1204222}
 *
 */

#include <stdio.h>

int main(void) {
  unsigned char a;
  unsigned char b;
  unsigned char h;

  scanf("%hhu, %hhu, %hhu", &a, &b, &h);

  double res = (a + b) * h / 2.0;
  printf("%.1f", res);

  return 0;
}
