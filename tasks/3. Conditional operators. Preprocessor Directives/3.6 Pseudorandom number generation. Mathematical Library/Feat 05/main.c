/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191266/step/7?unit=1204237}
 *
 */

#include <stdio.h>
#include <stdlib.h>

#define RAND_MAX 32767

int main(void) {
  int a;
  int b;
  double y1;
  double y2;
  double y3;
  double y4;
  double y5;
  double y6;
  double y7;
  double y8;
  double y9;
  double y10;

  if (scanf("%d %d", &a, &b) != 2) {
    printf("expected two integers!");

    return 0;
  }

  y1 = ((double)rand() / (double)RAND_MAX) * (double)(b - a) + (double)a;
  y2 = ((double)rand() / (double)RAND_MAX) * (double)(b - a) + (double)a;
  y3 = ((double)rand() / (double)RAND_MAX) * (double)(b - a) + (double)a;
  y4 = ((double)rand() / (double)RAND_MAX) * (double)(b - a) + (double)a;
  y5 = ((double)rand() / (double)RAND_MAX) * (double)(b - a) + (double)a;
  y6 = ((double)rand() / (double)RAND_MAX) * (double)(b - a) + (double)a;
  y7 = ((double)rand() / (double)RAND_MAX) * (double)(b - a) + (double)a;
  y8 = ((double)rand() / (double)RAND_MAX) * (double)(b - a) + (double)a;
  y9 = ((double)rand() / (double)RAND_MAX) * (double)(b - a) + (double)a;
  y10 = ((double)rand() / (double)RAND_MAX) * (double)(b - a) + (double)a;

  printf("%.2lf %.2lf %.2lf %.2lf %.2lf %.2lf %.2lf %.2lf %.2lf %.2lf", y1, y2,
         y3, y4, y5, y6, y7, y8, y9, y10);

  return 0;
}
