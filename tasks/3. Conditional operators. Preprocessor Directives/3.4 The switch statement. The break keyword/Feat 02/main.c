/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191263/step/4?unit=1204234}
 *
 */

#include <stdio.h>

int main(void) {
  char symbol;

  if (scanf("%c", &symbol) != 1) {
    printf("Input error.");

    return 0;
  }

  switch (symbol) {
  case 'a':
    symbol -= 32;
    break;
  case 'b':
    symbol -= 32;
    break;
  case 'c':
    symbol -= 32;
    break;
  case 'd':
    symbol -= 32;
    break;
  case 'e':
    symbol -= 32;
    break;
  default:
    symbol -= 32;
    break;
  }

  printf("%c", symbol);

  /**
   * макроопределение для тестирования
   * (не убирать и должно идти непосредственно перед return 0)
   */
  __ASSERT_TESTS__
  return 0;
}
