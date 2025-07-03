/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191295/step/4?unit=1204283}
 *
 */

#include <stdio.h>

#define SIZE_BUFFER 128

int main(void) {
  int buffer[SIZE_BUFFER];
  int temp;
  int count = 0;
  int buffer_length = sizeof(buffer) / sizeof(*buffer);
  // part of calculating actual index of buffer elem
  // @see example below
  int index_computing = 0;

  while (count < buffer_length && scanf("%d", &buffer[count]) == 1) {
    count += 1;
  }

  index_computing = count % 2 == 0 ? count / 2 : count / 2 + 1;

  // max buffer_length = 128, but if count < buffer_length
  // e.g. count = 5 => buffer{1, 2, 3, 4, 5, 0 x 123}
  // but expected {1, 2, 3, 4, 5} to get => {4, 5, 3, 1, 2}
  /**
   * @example
   *    6 70 8 9 10 1 20 3 4 5 11 =>
   *      {20, 3, 4, 5, 11, 1, 6, 70, 8, 9, 10}
   *    6 70 8 9 10 1 20 3 4 5 =>
   *      {1, 20, 3, 4, 5, 6, 70, 8, 9, 10}
   *    -654 5345 24 54 5466 987 343 234 =>
   *      {-654, 5345, 24, 54, 5466, 987, 343, 234}
   *    -654 5345 24 54 5466 987 343 234 128 =>
   *      {987, 343, 234, 128, 5466, -654, 5345, 24, 54}
   */
  for (int i = 0; i < count / 2; i += 1) {
    /**
     * @example
     *    buffer{1, 2, 3, 4, 5} count = 5 =>
     *    index_computing = count / 2 + 1
     *    i = 0
     *    temp = buffer[count / 2 + 1 + 0] =
     *       = buffer[index_computing + 0] = 4
     *    buffer[count / 2 + 1 + 0] =>
     *      buffer[index_computing + 0] = buffer[0] = 1
     *    buffer[0] = temp = 4
     *    i = 1
     *    temp = buffer[index_computing + 1] = 5
     *    buffer[index_computing + 1] = buffer[1] = 2
     *    buffer[1] = temp = 5
     *
     *    *    buffer{1, 2, 3, 4, 5, 6} count = 6 =>
     *    index_computing = count / 2
     *    i = 0
     *    temp = buffer[count / 2 + 0] =
     *       = buffer[index_computing + 0] = 4
     *    buffer[count / 2 + 0] =>
     *      buffer[index_computing + 0] = buffer[0] = 1
     *    buffer[0] = temp = 4
     *    i = 1
     *    temp = buffer[index_computing + 1] = 5
     *    buffer[index_computing + 1] = buffer[1] = 2
     *    buffer[1] = temp = 5
     */
    temp = buffer[index_computing + i];
    buffer[index_computing + i] = buffer[i];
    buffer[i] = temp;
  }

  for (unsigned char i = 0; i < count; i += 1) {
    printf("%d ", buffer[i]);
  }

  return 0;
}
