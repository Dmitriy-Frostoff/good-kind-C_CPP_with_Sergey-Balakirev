/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191262/step/7?unit=1204233}
 *
 */

#include <stdio.h>

int main(void) {
  int width;
  int height;
  int border;

  if (scanf("%d %d", &width, &height) != 2) {
    printf("expected two integers!");

    return 0;
  }

  border = (width > height ? width : height) + 8;

  printf("%d", border);

  return 0;
}
