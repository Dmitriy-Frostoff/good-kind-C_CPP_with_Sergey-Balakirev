/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191263/step/7?unit=1204234}
 *
 */

#include <stdio.h>

int show_menu(void) {
  char menu_item;

  printf("a) learning english\n\
b) learning C/C++\n\
c) learning mathematic\n\
d) learning Python\n");

  if (scanf("%c", &menu_item) != 1) {
    printf("Expected one integer!");
    return 0;
  }

  switch (menu_item) {
  case 'a':
  case 'A':
    return 1;
  case 'b':
  case 'B':
    return 2;
  case 'c':
  case 'C':
    return 3;
  case 'd':
  case 'D':
    return 4;
  default:
    return -1;
  }
}

int main(void) {
  int item = show_menu();

  printf("%d", item);

  return 0;
}
