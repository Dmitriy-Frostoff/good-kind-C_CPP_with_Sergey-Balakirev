/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191305/step/8?unit=1204293}
 *
 */

#include "./config.h"
#include "./utils.h"

/**
 *  @brief fill the 2d matrix from the input, transpose it and print to the
 *  terminal
 *
 *  @example
 *    1 2 3 4
 *    5 6 7 8
 *    9 8 7 6
 *    5 4 3 2 =>
 *    OUTPUT: >>>
 *    1 5 9 5
 *    2 6 8 4
 *    3 7 7 3
 *    4 8 6 2
 */
int main(void) {
  short matrix[SIZE][SIZE] = {0};

  // fill 'matrix' array
  fill_matrix(matrix);

  // transpose matrix
  transpose(matrix);

  // print transposed matrix
  print_matrix(matrix);

  return 0;
}
