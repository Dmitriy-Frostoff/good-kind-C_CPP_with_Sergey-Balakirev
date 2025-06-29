/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191245/step/5?unit=1204216}
 *
 * The program must read one character (byte) from the input stream using the
 * 'getchar()' function and output it to the output stream using the 'putchar()'
 * function.
 *
 */
#include <stdio.h>

int main(void) {
  int inputData = getchar();
  putchar(inputData);

  return 0;
}
