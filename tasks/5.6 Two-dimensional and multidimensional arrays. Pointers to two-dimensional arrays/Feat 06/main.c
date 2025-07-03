/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191296/step/8?unit=1204284}
 *
 */

#include <stdio.h>

#define ROWS_COUNT 4
#define COLUMNS_COUNT 3

int main(void) {
  int ar_2D[ROWS_COUNT][COLUMNS_COUNT];
  int rows_count = sizeof(ar_2D) / sizeof(*ar_2D);
  int columns_count = sizeof(*ar_2D) / sizeof(*ar_2D[0]);
  int ar_2D_elems_count = ROWS_COUNT * COLUMNS_COUNT;
  int count = 0;

  /**
   *  @example
   *    1 2 3 4 5 6 7 8 9 10 11 12 and ar_2D[4][3]=>
   *      ar_2D{
   *        {1, 2, 3},
   *        {4, 5, 6},
   *        {7, 8, 9},
   *        {10, 11, 12}
   *      }
   */
  for (int i = 0; i < rows_count; i += 1) {
    for (int j = 0; j < columns_count; j += 1) {
      if (count < ar_2D_elems_count && scanf("%d ", &ar_2D[i][j]) == 1) {
        count += 1;
      }
    }
  }

  /**
   *  @example
   *      ar_2D{
   *        {1, 2, 3},
   *        {4, 5, 6},
   *        {7, 8, 9},
   *        {10, 11, 12}
   *      } =>
   *      {
   *        {1, 4, 7, 10},
   *        {2, 5, 8, 11},
   *        {3, 6, 9, 12},
   *      }
   */
  for (int i = 0; i < columns_count; i += 1) {
    for (int j = 0; j < rows_count; j += 1) {
      if (j == rows_count - 1) {
        printf("%d\n", ar_2D[j][i]);
        continue;
      }
      printf("%d ", ar_2D[j][i]);
    }
  }

  /**
   *  макроопределение для тестирования
   *  (не убирать и должно идти непосредственно перед return 0)
   */
  __ASSERT_TESTS__
  return 0;
}
