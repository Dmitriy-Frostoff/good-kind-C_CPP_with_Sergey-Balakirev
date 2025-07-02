/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191288/step/8?unit=1204276}
 *
 * Declare 'ptr_k' pointer to variable 'k'. Increase 'k' value by 10 via 'ptr_k'
 *
 */

#include <stdio.h>

int main(void) {
  int init;
  int k;
  int *ptr_k = NULL;

  if (scanf("%d", &init) != 1) {
    printf("expected one integer");
    return 0;
  }

  k = init;

  ptr_k = &k;
  *ptr_k += 10;

  /**
   *    макроопределение для тестирования
   *    (не убирать и должно идти непосредственно перед return 0)
   */
  __ASSERT_TESTS__
  return 0;
}
