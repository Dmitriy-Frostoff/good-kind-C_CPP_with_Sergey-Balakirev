/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191249/step/7?unit=1204220}
 */
#include <stdio.h>

int main(void) {
  int a;
  short b;
  float c;
  double d;

  scanf("%d %hd %f %lf", &a, &b, &c, &d);
  printf("%d %d %.2f %.2f", a, b, c, d);

  return 0;
}
