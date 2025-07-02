/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191287/step/4?unit=1204275}
 *
 */

#include <stdio.h>

int main(void) {
  int n = 5;
  int m = 7;
  int total = 5;

  for (int i = 0; i < total; i += 1) {
    int x;
    int y;

    if (scanf("%d, %d", &x, &y) != 2) {
      printf("expected two integers");
      return 0;
    }

    if (x < 1 || x > n || y < 1 || y > m) {
      continue;
    }

    printf("(%d, %d)\n", x, y);
  }

  return 0;
}
