/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191249/step/13?unit=1204220}
 *
 */
#include <stdio.h>

int main(void) {
  int a;
  int b;
  int c;

  scanf("%d %d", &a, &b);

  // exchange values of a and b
  c = a;
  a = b;
  b = c;

  printf("%d %d", a, b);

  return 0;
}
