/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191295/step/9?unit=1204283}
 *
 */

#include <stdio.h>

#define TOTAL 20

int main(void) {
  float ws[TOTAL] = {0.0f};
  int count = 0;
  int curr_elem_index;
  int ws_length = sizeof(ws) / sizeof(*ws);

  while (count < ws_length && scanf("%f", &ws[count]) == 1) {
    count += 1;
  }

  for (int i = 0; i < count; i += 1) {
    curr_elem_index = i;

    /**
     * @example
     *    ws{-3, 5, 0, -8, 1, 10} =>
     *      curr_elem_index = 0, i = 0 =>
     *      ws[curr_elem_index] > ws[i + 1] =>
     *      ws[0] > ws[1] => -3 > 5 ? false
     *      ...
     *      ws[0] > ws[2] => -3 > 0 ? false
     *      ws[0] > ws[3] => -3 > -8 ? true =>
     *      curr_elem_index = 3;
     *      ws[3] > ws[4] => -3 > 1 ? false
     *      ws[3] > ws[5] => -3 > 10 ? false
     */
    for (int j = i + 1; j < count; j += 1) {
      if (ws[curr_elem_index] > ws[j]) {
        curr_elem_index = j;
      }
    }

    /**
     *  @example
     *    ws{-3, 5, 0, -8, 1, 10} and curr_elem_index = 3 =>
     *      ws{-8, 5, 0, -3, 1, 10}
     *
     *  @note
     *    curr_elem_index == i =>
     *      through over the cycle
     *      ws[curr_elem_index] < ws[i + 1] =>
     *      nothing to change
     */
    if (curr_elem_index != i) {
      float temp = ws[i];
      ws[i] = ws[curr_elem_index];
      ws[curr_elem_index] = temp;
    }
  }

  for (int i = 0; i < count; i += 1) {
    printf("%.2f ", ws[i]);
  }

  return 0;
}
