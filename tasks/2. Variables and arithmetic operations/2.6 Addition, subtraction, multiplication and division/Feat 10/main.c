/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191251/step/12?unit=1204222}
 *
 */

#include <stdio.h>

int main(void) {
  double radius;
  double PI = 3.1415;

  scanf("%lf", &radius);

  double circleLength = 2 * PI * radius;
  printf("%.3f", circleLength);

  return 0;
}
