/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191281/step/7?unit=1204269}
 *
 */

#include <stdio.h>

#define PI 3.1415
#define GRAD 180 / PI

int main(void) {
  double rad;
  double grad;

  if (scanf("%lf", &rad) != 1) {
    printf("expected one real number as radian of angle!");

    return 0;
  }

  grad = rad * GRAD;

  printf("%.2f", grad);

  return 0;
}
