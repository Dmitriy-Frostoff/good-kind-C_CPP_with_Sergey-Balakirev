/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191260/step/7?unit=1204231}
 *
 */

#include <stdio.h>

int main(void) {
  unsigned int a;
  unsigned int b;
  unsigned int c;

  if (scanf("%u, %u, %u", &a, &b, &c) != 3) {
    printf("Input error.");
    return 0;
  }

  if (c * c == a * a + b * b) {
    printf("yes");

    return 0;
  }

  printf("no");

  return 0;
}
