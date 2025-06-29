/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191251/step/6?unit=1204222}
 *
 */
#include <stdio.h>

int main(void) {
  int h;
  int w;
  scanf("%d %d", &h, &w);

  double res = (double)h / (double)w;
  printf("%.2f", res);

  return 0;
}
