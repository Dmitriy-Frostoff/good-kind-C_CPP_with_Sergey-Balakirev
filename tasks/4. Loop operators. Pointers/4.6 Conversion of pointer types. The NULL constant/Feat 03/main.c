/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191289/step/5?unit=1204277}
 *
 */

#include <stdio.h>

int main(void) {
  short a;
  short b;
  short *ptr_a;
  short *ptr_b;

  if (scanf("%hd, %hd", &a, &b) != 2) {
    printf("expected two integers");
    return 0;
  }

  void *ptr_stash;
  ptr_a = &a;
  ptr_b = &b;

  ptr_stash = ptr_a;

  ptr_a = ptr_b;
  ptr_b = ptr_stash;

  printf("%d %d", *ptr_a, *ptr_b);

  /**
   * макроопределение для тестирования
   * (не убирать и должно идти непосредственно перед return 0)
   */
  __ASSERT_TESTS__
  return 0;
}
