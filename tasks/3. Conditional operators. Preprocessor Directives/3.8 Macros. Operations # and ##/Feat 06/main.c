/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191282/step/8?unit=1204270}
 *
 */

#include <stdio.h>

#define MUL_VAR_NAME(var1, var2) mul_##var1##_##var2

int main(void) {
  int num1;
  int num2;

  if (scanf("%d %d", &num1, &num2) != 2) {
    printf("expected two integers");

    return 0;
  }

  int MUL_VAR_NAME(num1, num2) = num1 * num2;

  printf("%d", MUL_VAR_NAME(num1, num2));

  /**
   * макроопределение для тестирования
   * (не убирать и должно идти непосредственно перед return 0)
   */

  __ASSERT_TESTS__
  return 0;
}
