/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191289/step/6?unit=1204277}
 *
 */

#include <stdio.h>

int main(void) {
  int var;
  int *ptr_var;
  char *ptr_ch;

  if (scanf("%d", &var) != 1) {
    printf("expected one integer");
    return 0;
  }

  ptr_var = &var;
  ptr_ch = (char *)ptr_var;

  printf("%d", *ptr_ch);

  /**
   * макроопределение для тестирования
   * (не убирать и должно идти непосредственно перед return 0)
   */
  __ASSERT_TESTS__
  return 0;
}
