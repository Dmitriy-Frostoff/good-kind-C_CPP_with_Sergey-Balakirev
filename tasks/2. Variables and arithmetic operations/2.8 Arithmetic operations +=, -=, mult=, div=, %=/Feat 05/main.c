/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191255/step/7?unit=1204226}
 *
 */

#include <stdio.h>

int main(void) {
  double height;
  double width;
  double perimeter;

  scanf("%lf %lf", &height, &width);

  perimeter = 2 * (width + height);

  printf("Периметр: %.1f", perimeter);

  return 0;
}
