/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191296/step/10?unit=1204284}
 *
 */

#include <stdio.h>

#define ROWS 3
#define COLS 4

int main(void) {
  int a[ROWS][COLS] = {0};
  int b[ROWS][COLS] = {0};
  int res[ROWS][COLS];

  int arr_size = ROWS * COLS;

  int *ptr_a = &a[0][0];
  int *ptr_b = &b[0][0];

  int temp;

  for (int i = 0; i < arr_size && scanf("%d ", &temp) == 1; i += 1) {
    *(ptr_a + i) = temp;
  }

  for (int i = 0; i < arr_size && scanf("%d ", &temp) == 1; i += 1) {
    *(ptr_b + i) = temp;
  }

  /**
   *  @example
   *    a{
   *      {1, 2, 3, 4},
   *      {5, 6, 7, 8},
   *      {9, 10, 11, 12},
   *    }
   *    and
   *    b{
   *      {2, 3, 2, 0},
   *      {5, 3, 5, 8},
   *      {1, 24, 32, 10},
   *    } =>
   *    res{
   *      {3, 5, 5, 4},
   *      {10, 9, 12, 16},
   *      {10, 34, 43, 22},
   *    } =>
   *      3 5 5 4\n
   *      10 9 12 16\n
   *      10 34 43 22\n
   */
  for (int i = 0; i < ROWS; i += 1) {
    for (int j = 0; j < COLS; j += 1) {
      res[i][j] = a[i][j] + b[i][j];
      printf("%d", res[i][j]);

      if (j == COLS - 1) {
        printf("\n");
        continue;
      }
      printf(" ");
    }
  }

  return 0;
}
