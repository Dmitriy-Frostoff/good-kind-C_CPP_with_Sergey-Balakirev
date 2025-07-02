/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191288/step/10?unit=1204276}
 *
 * Declare 'ptr_a' pointer to 'a' variable and 'ptr_b' to 'b' variable. Via
 * 'ptr_a' and 'ptr_b' switch values of 'a' and 'b' variabled
 *
 */

#include <stdio.h>

int main(void) {
  short a;
  short b;
  short init_a;
  short init_b;
  short *ptr_a;
  short *ptr_b;

  if (scanf("%hd, %hd", &a, &b) != 2) {
    printf("expected two integers each in range [0; 32768)");
    return 0;
  }

  init_a = a;
  init_b = b;
  ptr_a = &a;
  ptr_b = &b;

  *ptr_a = init_b;
  *ptr_b = init_a;

  /**
   * макроопределение для тестирования
   * (не убирать и должно идти непосредственно перед return 0)
   */
  __ASSERT_TESTS__
  return 0;
}
