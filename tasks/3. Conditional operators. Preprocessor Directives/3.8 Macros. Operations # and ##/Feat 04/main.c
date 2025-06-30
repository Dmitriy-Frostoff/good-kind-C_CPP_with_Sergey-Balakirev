/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191282/step/6?unit=1204270}
 *
 */

#include <math.h>
#include <stdio.h>

#define GIPOT(a, b) hypot(a, b)

int main(void) {
  unsigned int a;
  unsigned int b;
  double length;

  if (scanf("%d, %d", &a, &b) != 2) {
    printf("Expected two positive integers");

    return 0;
  }

  length = GIPOT(a + 3, b - 2);

  printf("%.2f", length);

  /**
   * макроопределение для тестирования
   * (не убирать и должно идти непосредственно перед return 0)
   */
  __ASSERT_TESTS__
  return 0;
}
