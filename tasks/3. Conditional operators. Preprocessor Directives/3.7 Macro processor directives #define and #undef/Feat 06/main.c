/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191281/step/8?unit=1204269}
 *
 */

#include <stdio.h>

#define MAX_WIDTH 256
#define MAX_HEIGHT 500

int main(void) {
  double width;
  double height;

  if (scanf("%lf %lf", &width, &height) != 2) {
    printf("expected two positive real numbers!");

    return 0;
  }

  if (width > MAX_WIDTH) {
    width = MAX_WIDTH;
  }

  if (height > MAX_HEIGHT) {
    height = MAX_HEIGHT;
  }

  printf("%.1f %.1f", width, height);

  return 0;
}
