/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191285/step/5?unit=1204273}
 *
 */

#include <stdio.h>

int main(void) {
  int a1;
  int d;
  int n;

  if (scanf("%d; %d; %d", &a1, &d, &n) != 3) {
    printf("expected three integers");

    return 0;
  }

  printf("%d ", a1);

  // i = 1 => a1
  // i <= n => because a1 member (i = 1, start from 1) of the arithmetic
  // progression was got from the input
  for (int i = 2; i <= n; i += 1) {
    printf("%d ", a1 + (i - 1) * d);
  }

  return 0;
}
