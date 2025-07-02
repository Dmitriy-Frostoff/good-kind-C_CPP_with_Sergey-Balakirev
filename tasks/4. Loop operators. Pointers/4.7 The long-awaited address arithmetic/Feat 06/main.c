/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191290/step/8?unit=1204278}
 *
 */

#include <stddef.h>
#include <stdio.h>

int main(void) {
  int count;
  unsigned char mask = 0b0001001;

  if (scanf("%d", &count) != 1) {
    printf("expected one integer");
    return 0;
  }

  int *ptr_count = &count;
  // pointer window (1 byte) over the ptr_count (4 bytes)
  char *ptr_byte_at_count = (char *)ptr_count;

  /**
   * switch on bytes 0 and 3 via pointer window moving (over bytes)
   * and bitwise-inclusive-OR (|) (over bits)
   * @example
   *    int 0 => 0b0000000 0b0000000 0b0000000 0b0000000
   *        => 0b0001001 0b0001001 0b0001001 0b0001001
   */
  for (size_t i = 0; i < sizeof(count); i += 1) {
    /**
     * @example
     *    0b0000000 | 0b0001001 => 0b0001001
     */
    *ptr_byte_at_count = *ptr_byte_at_count | mask;
    // goto next byte
    ptr_byte_at_count += 1;
  }

  ptr_byte_at_count = (char *)ptr_count;

  printf("%d\n", count);

  return 0;
}
