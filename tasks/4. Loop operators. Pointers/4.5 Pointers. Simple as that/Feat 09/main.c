/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191288/step/11?unit=1204276}
 *
 */

#include <stdio.h>

int main(void) {
  short a;
  short b;
  short *ptr_a;
  short *ptr_b;
  short res;

  if (scanf("%hd, %hd", &a, &b) != 2) {
    printf("expected two integers each in range [0; 32768)");
    return 0;
  }

  ptr_a = &a;
  ptr_b = &b;

  res = *ptr_a * *ptr_b;

  printf("%d", res);

  /**
   * макроопределение для тестирования
   * (не убирать и должно идти непосредственно перед return 0)
   */
  __ASSERT_TESTS__
  return 0;
}
