/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191296/step/9?unit=1204284}
 *
 */

#include <stdio.h>

#define ROWS 3
#define COLS 5
#define MEAN_LENGTH ROWS

int main(void) {
  short vls[ROWS][COLS] = {0};
  short *ptr_vls = &vls[0][0];
  short rows_count = sizeof(vls) / sizeof(*vls);
  short columns_count = sizeof(*vls) / sizeof(*vls[0]);
  double mean[MEAN_LENGTH];
  double sum = 0;

  short x;

  /**
   *  @example
   *    1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 =>
   *      {
   *        {1, 2, 3, 4, 5},
   *        {6, 7, 8, 9, 10},
   *        {11, 12, 13, 14, 15}
   *      }
   */
  for (short i = 0; i < rows_count * columns_count && scanf("%hd", &x) == 1;
       i += 1) {
    *ptr_vls = x;
    ptr_vls += 1;
  }

  /**
   *  @example
   *    {
   *      {1, 2, 3, 4, 5},
   *      {6, 7, 8, 9, 10},
   *      {11, 12, 13, 14, 15}
   *    } and mean[3]{0} =>
   *      {15(1 + 2 + 3 + 4 + 5) / columns_count(= 5), 40 / 5, 65 / 5} =>
   *      {3.00, 8.00, 13.00}
   */
  for (short i = 0; i < rows_count; i += 1) {
    // reset sum
    sum = 0;

    for (short j = 0; j < columns_count; j += 1) {
      sum += vls[i][j];
    }

    mean[i] = sum / (double)columns_count;
    printf("%.2f ", mean[i]);
  }

  /**
   *  макроопределение для тестирования
   *  (не убирать и должно идти непосредственно перед return 0)
   */
  __ASSERT_TESTS__
  return 0;
}
