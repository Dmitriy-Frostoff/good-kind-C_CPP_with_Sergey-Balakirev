/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191282/step/4?unit=1204270}
 *
 */

#include <stdio.h>

#define MAX_WIDTH 1280
#define GET_WIDTH(W) W <= MAX_WIDTH ? W : MAX_WIDTH

int main(void) {
  int width;

  if (scanf("%d", &width) != 1) {
    printf("expected one integer");

    return 0;
  }

  width = GET_WIDTH(width);

  printf("width = %d", width);

  /**
   * макроопределение для тестирования
   * (не убирать и должно идти непосредственно перед return 0)
   */
  __ASSERT_TESTS__
  return 0;
}
