/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191289/step/7?unit=1204277}
 *
 */

#include <stdio.h>

int main(void) {
  short var;

  if (scanf("%hd", &var) != 1) {
    printf("expected one integer");
    return 0;
  }

  short *ptr_var = NULL;
  ptr_var = &var;
  char *ptr_ch = NULL;
  ptr_ch = (char *)ptr_var;
  *ptr_ch = 2;

  printf("%d", var);

  /**
   * макроопределение для тестирования
   * (не убирать и должно идти непосредственно перед return 0)
   */
  __ASSERT_TESTS__
  return 0;
}
