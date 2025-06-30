/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191262/step/8?unit=1204233}
 *
 */

#include <stdio.h>

int main(void) {
  short type = 0;
  double w;
  double h;

  if (scanf("%hd %lf %lf", &type, &w, &h) != 3) {
    printf("Input error.");
    return 0;
  }

  type == 1 ? printf("%.1f", w * h)
            : (type == 2 ? printf("%.1f", 2 * (w + h)) : printf("%d", -1));

  return 0;
}
