/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191282/step/5?unit=1204270}
 *
 */

#include <math.h>
#include <stdio.h>

#define GET_MAX(num1, num2) fmax(num1, num2)

int main(void) {
  double val_1;
  double val_2;
  double maxNum;

  if (scanf("%lf; %lf", &val_1, &val_2) != 2) {
    printf("Input error");

    return 0;
  }

  double res = GET_MAX(val_1 + 1, val_2 - 1) / (val_1 + val_2);

  printf("%.2f", res);

  /**
   * макроопределение для тестирования
   * (не убирать и должно идти непосредственно перед return 0)
   */

  __ASSERT_TESTS__
  return 0;
}
