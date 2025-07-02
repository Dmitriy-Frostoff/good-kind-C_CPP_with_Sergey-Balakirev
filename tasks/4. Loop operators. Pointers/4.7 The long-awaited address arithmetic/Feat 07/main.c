/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191290/step/9?unit=1204278}
 *
 */

#include <stdio.h>

int main(void) {
  int count;
  char mask = 0b11000010;

  if (scanf("%d", &count) != 1) {
    printf("expected one integer");
    return 0;
  }

  int *ptr_count = &count;
  // pointer window (1 byte) over the ptr_count (4 bytes)
  char *ptr_byte_at_count = (char *)ptr_count;

  /**
   * switch off bytes 1, 6 and 7 via pointer window moving (over bytes)
   * and bitwise AND operator (&) and bitwise NOT (~) operator (over bits)
   * @example
   *    int 193 => 0b11000010 0b11000010 0b11000010 0b11000010
   *        => 0b00000000 0b00000000 0b00000000 0b00000000
   */
  for (unsigned char i = 0; i < sizeof(count); i += 1) {
    /**
     * @example
     *    0b11000010 & ~0b11000010 =>
     *        0b11000010 & 0b00111101 => 0b00000000
     */
    *ptr_byte_at_count = *ptr_byte_at_count & ~mask;
    // goto next byte
    ptr_byte_at_count += 1;
  }

  // reset pointer to 1st byte of ptr_count
  ptr_byte_at_count = (char *)ptr_count;

  printf("%d\n", count);

  return 0;
}
