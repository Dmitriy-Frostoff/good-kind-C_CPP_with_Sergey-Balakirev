/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191285/step/6?unit=1204273}
 *
 */

#include <math.h>
#include <stdio.h>

int main(void) {
  int b1;
  int q;
  int n;

  if (scanf("%d; %d; %d", &b1, &q, &n) != 3) {
    printf("expected three integers");

    return 0;
  }

  for (int i = 0; i < n; i += 1) {
    printf("%d ", b1 * (int)pow(q, i));
  }

  return 0;
}
