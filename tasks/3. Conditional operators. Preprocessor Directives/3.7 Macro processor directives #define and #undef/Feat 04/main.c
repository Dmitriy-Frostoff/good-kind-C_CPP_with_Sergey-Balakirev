/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191281/step/6?unit=1204269}
 *
 */

#include <stdio.h>

#define KMH 3600 / 1000

int main(void) {
  int s_mc;
  double s_kmh;

  if (scanf("%d", &s_mc) != 1) {
    printf("expected one pisitive integer!");

    return 0;
  }

  s_kmh = (double)s_mc * (double)KMH;

  printf("%.2f", s_kmh);

  return 0;
}
