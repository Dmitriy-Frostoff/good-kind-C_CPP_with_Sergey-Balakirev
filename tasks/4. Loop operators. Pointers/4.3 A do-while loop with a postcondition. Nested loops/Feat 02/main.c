/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191286/step/4?unit=1204274}
 *
 */

#include <stdio.h>

int main(void) {
  int p = 1;
  int n;

  if (scanf("%d", &n) != 1) {
    printf("expected one integer");
    return 0;
  }

  int i = 1;

  do {
    p *= i;
    i += 1;
  } while (i <= n);

  printf("%d", p);

  return 0;
}
