/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191247/step/4?unit=1204218}
 *
 * The program must read the first three consecutive characters from the input
 * stream using the 'getchar()' function, and then output them to the output
 * stream in reverse order (from the last to the first) using the 'putchar()'
 * function.
 *
 * P.S. In tests, it is guaranteed that at least three characters are present in
 * the input stream.
 *
 */
#include <stdio.h>

int main(void) {
  int char0 = getchar();
  int char1 = getchar();
  int char2 = getchar();
  putchar(char2);
  putchar(char1);
  putchar(char0);

  return 0;
}
