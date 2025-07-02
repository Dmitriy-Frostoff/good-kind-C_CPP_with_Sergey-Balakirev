/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191292/step/6?unit=1204280}
 *
 * There's an array with the name 'pows' that consist of element of type float.
 * In the main() function, output the values of its elements to the console in
 * one line separated by a space in reverse order, accurate to tenths.
 *
 */

#include <stddef.h>
#include <stdio.h>

int main(void) {
  // size_t => char
  // do not use !!!'unsigned'!!! Or one will get the infinite loop
  // in the further cycle (i < 0 but unsigned always >= 0)
  char pows_length = sizeof(pows) / sizeof(*pows);

  for (char i = pows_length - 1; i >= 0; i -= 1) {
    printf("%.1f ", pows[i]);
  }

  return 0;
}
