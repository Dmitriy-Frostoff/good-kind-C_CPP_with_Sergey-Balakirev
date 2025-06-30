/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191266/step/6?unit=1204237}
 *
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int a;
  int b;
  int y1;
  int y2;
  int y3;
  int y4;
  int y5;
  int y6;
  int y7;
  int y8;
  int y9;
  int y10;

  if (scanf("%d %d", &a, &b) != 2) {
    printf("expected two integers");

    return 0;
  }

  y1 = rand() % (b - a + 1) + a;
  y2 = rand() % (b - a + 1) + a;
  y3 = rand() % (b - a + 1) + a;
  y4 = rand() % (b - a + 1) + a;
  y5 = rand() % (b - a + 1) + a;
  y6 = rand() % (b - a + 1) + a;
  y7 = rand() % (b - a + 1) + a;
  y8 = rand() % (b - a + 1) + a;
  y9 = rand() % (b - a + 1) + a;
  y10 = rand() % (b - a + 1) + a;

  printf("%d %d %d %d %d %d %d %d %d %d", y1, y2, y3, y4, y5, y6, y7, y8, y9,
         y10);

  return 0;
}
