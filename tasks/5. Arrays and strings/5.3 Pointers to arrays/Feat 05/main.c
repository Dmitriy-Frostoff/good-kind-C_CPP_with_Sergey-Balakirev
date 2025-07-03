/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191293/step/7?unit=1204281}
 *
 */

#include <stdio.h>

int main(void) {
  int value;
  char ar_d[sizeof(value)];

  unsigned char *ptr_byte_at_value = NULL;

  if (scanf("%d ", &value) != 1) {
    printf("expected one integer");
    return 0;
  }

  ptr_byte_at_value = &value;

  /**
   * @example
   *    int 1025 = 0041(base256) => 1 * 256 ** 0 + 4 * 256 ** 1
   *    (int = 4 bytes => 41 => 0041)
   *    byte0(1), byte1(4), byte2(0), byte3(0) => 1400
   *
   *    int 1025 and ar_d{undef x 4} => {1, 4, 0, 0}
   */
  for (unsigned char i = 0; i < sizeof(value); i += 1) {
    /**
     * @example
     *    ptr_byte_at_value is not mutated
     *    ar_d[0] = *(ptr_byte_at_value + 0)
     *    ar_d[1] = *(ptr_byte_at_value + 1)
     */
    ar_d[i] = *(ptr_byte_at_value + i);
    printf("%d ", ar_d[i]);
  }

  /**
   * макроопределение для тестирования
   * (не убирать и должно идти непосредственно перед return 0)
   */
  __ASSERT_TESTS__
  return 0;
}
