/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191290/step/7?unit=1204278}
 *
 */

#include <stdio.h>

int main(void) {
  int value;

  if (scanf("%d", &value) != 1) {
    printf("expected one integer");
    return 0;
  }

  // get pointer @type{int} for value variable
  int *ptr_value = &value;
  // get pointer @type{short} as two bytes window
  // to move it over the ptr_value
  short *ptr_byte_value = (short *)ptr_value;

  /**
   *  @example
   *    int value = 325476 => 391013
   *    iteration 0
   *    short ptr_byte_value (bytes 0 and 1) = 379807260,
   *        value here is => *ptr_byte_value = -2204
   *    iteration 1
   *    short ptr_byte_value (bytes 2 and 3) = 379807262,
   *        value here is => *ptr_byte_value = 4
   *    => increase by 1 the number at @type{short} (bytes 0 and 1)
   *        and the number at @type{short} (bytes 2 and 3)
   */
  for (unsigned char i = 0; i < 2; i += 1) {
    *ptr_byte_value += 1;
    ptr_byte_value += 1;
  }

  printf("%d", value);

  return 0;
}
