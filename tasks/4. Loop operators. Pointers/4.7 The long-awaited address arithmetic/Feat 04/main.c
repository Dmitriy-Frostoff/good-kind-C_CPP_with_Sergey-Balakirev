/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191290/step/6?unit=1204278}
 *
 * Print to the console (space separated) all the 8 bytes (start from 1 byte) of
 * varibale with type double
 *
 */

#include <stdio.h>

int main(void) {
  double value;

  if (scanf("%lf", &value) != 1) {
    printf("expected one real number");
    return 0;
  }

  // char = 1 byte
  // double = 8 bytes
  // type 'char' because we're need 1 byte window
  // to move it in cycle over the 8 bytes of type 'double'
  char *ptr_value = &value;

  /**
   * @example
   *    0.5 => 0 0 0 0 0 0 -32 63
   */
  for (size_t i = 0; i < sizeof(value); i += 1) {
    // print current value of the pointer
    printf("%d ", *ptr_value);
    // next byte of the 'value' variable
    ptr_value += 1;
  }

  return 0;
}
