/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191288/step/9?unit=1204276}
 *
 *  Declare 'ptr_a' pointer to 'a' variable. Via 'ptr_a' assign 'b'
 *  variable's value to 'a' variable. Print the 'a' variable value to the
 *  console as the one interger.
 *
 */

#include <stdio.h>

int main(void) {
  short a;
  short b;
  short *ptr_a;

  if (scanf("%hd", &b) != 1) {
    printf("expected one integer in range [0; 32768)");
    return 0;
  }

  ptr_a = &a;
  *ptr_a = b;

  printf("%d", a);

  /**
   *    макроопределение для тестирования
   *    (не убирать и должно идти непосредственно перед return 0)
   */
  __ASSERT_TESTS__
  return 0;
}
