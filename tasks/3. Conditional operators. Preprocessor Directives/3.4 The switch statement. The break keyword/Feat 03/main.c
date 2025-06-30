/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191263/step/5?unit=1204234}
 *
 */

#include <stdio.h>

int main(void) {
  char menu_item;
  short menu_number = 0;

  printf("a) learning english\n\
b) learning C/C++\n\
c) learning mathematic\n\
d) learning Python\n");

  if (scanf("%c", &menu_item) != 1) {
    printf("Input error.");
    return 0;
  }

  switch (menu_item) {
  case 'a':
  case 'A':
    menu_number = 1;
    printf("%d", menu_number);
    break;
  case 'b':
  case 'B':
    menu_number = 2;
    printf("%d", menu_number);
    break;
  case 'c':
  case 'C':
    menu_number = 3;
    printf("%d", menu_number);
    break;
  case 'd':
  case 'D':
    menu_number = 4;
    printf("%d", menu_number);
    break;
  default:
    menu_number = -1;
    printf("%d", menu_number);
    break;
  }

  /**
   * макроопределение для тестирования
   * (не убирать и должно идти непосредственно перед return 0)
   */
  __ASSERT_TESTS__
  return 0;
}
