/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191247/step/9?unit=1204218}
 *
 * The program should print the values of variables using a single printf()
 * function as follows:
 *
 * [ -123]
 * [    6]
 * [ 1024]
 * (there are 5 characters inside each square bracket). For format output, use
 * the flags of the specifiers.
 *
 * P.S. Do not use a space character in the format string of the printf()
 * function.
 *
 */
#include <stdio.h>

int main(void) {
  int a1 = -123;
  int a2 = 6;
  int a3 = 1024;

  printf("[%5d]\n[%5d]\n[%5d]\n", a1, a2, a3);

  return 0;
}
