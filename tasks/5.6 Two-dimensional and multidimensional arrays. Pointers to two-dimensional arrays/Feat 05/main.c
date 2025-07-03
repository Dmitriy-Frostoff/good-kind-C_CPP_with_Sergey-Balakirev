/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191296/step/7?unit=1204284}
 *
 */

#include <stdio.h>

#define ROWS_COUNT 3
#define COLUMN_COUNT 3

int main(void) {
  int ar_2D[ROWS_COUNT][COLUMN_COUNT];
  int rows_length = sizeof(ar_2D) / sizeof(*ar_2D);
  int columns_length = sizeof(*ar_2D) / sizeof(*ar_2D[0]);
  int count = 0;

  /**
   *  @example
   *    1 2 3 4 5 6 7 8 9 =>
   *      {
   *        {1, 2, 3},
   *        {4, 5, 6},
   *        {7, 8, 9}
   *      }
   */
  for (int i = 0; i < rows_length; i += 1) {
    for (int j = 0; j < columns_length; j += 1) {
      if (count < ROWS_COUNT * COLUMN_COUNT &&
          scanf("%d ", &ar_2D[i][j]) == 1) {
        count += 1;
      }
    }
  }

  /**
   * макроопределение для тестирования
   * (не убирать и должно идти непосредственно перед return 0)
   */
  __ASSERT_TESTS__
  return 0;
}
