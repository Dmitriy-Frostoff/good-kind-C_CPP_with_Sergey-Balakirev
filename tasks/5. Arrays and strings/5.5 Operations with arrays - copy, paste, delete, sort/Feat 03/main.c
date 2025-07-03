/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191295/step/5?unit=1204283}
 *
 */

#include <stdio.h>

#define TOTAL 10

int main(void) {
  int digs[TOTAL] = {0};
  int count = 0;
  int first_search_num_index = -1;
  int iteration_length = 0;
  int digs_length = sizeof(digs) / sizeof(*digs);

  while (count < digs_length && scanf("%d", &digs[count]) == 1) {
    count += 1;
  }

  // not always can be count == digs_length!
  // e.g. digs[10]{1, 2, 3, 4, 5, 5, 6, 7} =>
  //   count = 8, digs_length = 10
  for (int i = 0; i < count; i += 1) {
    if (digs[i] == 5) {
      first_search_num_index = i;
      break;
    }
  }

  // no search_num in the digs ? => print all the digs nums
  if (first_search_num_index == -1) {
    for (int i = 0; i < count; i += 1) {
      printf("%d ", digs[i]);
    }

    return 0;
  }

  /**
   * @example
   *    digs[10]{1, 2, 3, 4, 5, 5, 6, 7, 8, 9}
   *      count = 10, digs_length = 10
   *      (digs array will be cut by moving to the right)
   *
   *    digs[10]{1, 2, 3, 4, 5, 5, 6, 7}
   *      count = 8, digs_length = 10
   *      count + 1 => possible to move numbers to the right
   *      at least by one index
   *
   *    digs[10]{1, 2, 5, 4, 3} count = 5 =>
   *      count = 5, digs_length = 10
   *      count + 1 => possible to move numbers to the right
   *      at least by one index
   */
  iteration_length = count + 1 < digs_length ? count + 1 : digs_length;

  // move nums to the right at one position (+1 index)
  /**
   * @example
   *    digs[10]{1, 2, 3, 4, 5, 5, 6, 7, 8, 9} count = 10 =>
   *      iteration_length = digs_length =>
   *      digs max index = digs_length - 1 = 10 - 1 =>
   *      digs[digs_length - 1] = digs[(digs_length - 1) - 1] =>
   *      digs[9] = digs[8] => 8
   *      digs[8] = digs[7] => 7
   *      {1, 2, 3, 4, 5, 5, 5, 6, 7, 8}
   *
   *    digs[10]{1, 2, 3, 4, 5, 5, 6, 7, 0, 0} count = 8 =>
   *      iteration_length = count + 1 = 8 + 1 =>
   *      {1, 2, 3, 4, 5, 5, 5, 6, 7, 0}
   *
   *    digs[10]{1, 2, 5, 4, 3, 0 x 5} count = 5 =>
   *      iteration_length = count + 1 = 5 + 1 =>
   *      digs[iteration_length - 1] = digs[(iteration_length - 1) - 1]
   *      digs[5] = digs[4] => 3
   *      {1, 2, 5, 5, 4, 3, 0 x 4}
   */
  for (int i = iteration_length - 1; i >= first_search_num_index; i -= 1) {
    digs[i] = digs[i - 1];

    // nest -5 after first_search_num_index
    // {1, 2, 5, 5, 4, 3, 0 x 4} => {1, 2, 5, -5, 4, 3, 0 x 4}
    if (i == first_search_num_index + 1) {
      digs[i] = -5;
      break;
    }
  }

  for (int i = 0; i < iteration_length; i += 1) {
    printf("%d ", digs[i]);
  }

  return 0;
}
