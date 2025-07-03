#include "is_win.h"

/**
 *  @brief check the game field (2d array) left diagonal for a winner
 *
 *  @note !Impure function and functional princeples violation: under the hood
 *    it uses 'count_x_o_zero()' and 'check_xo_winner()' callbacks!
 *
 *  @param {char (*)[SIZE]} arr - 2d array of 'x', 'o' and '0'(zeros)
 *
 *  @return {int} - 1, 'x' have won
 *  @return {int} - 2, 'o' have won
 *  @return {int} - 3, 'draw' happend (not've got the winner and no more
 *    '0'(zeros))
 *  @return {int} - 0, game hadn't been finished (there're '0'zeros on the
 *    game field)
 *
 *  @throw - if inner param 'check_log' didn't change (defalut -1)
 *
 *  @example
 *    char arr[3][3] = {
 *      1, 0, 0
 *      0, 1, 2
 *      2, 0, 1
 *    }
 *      check_xo_left_diagonal(arr) => 1
 */
int check_xo_left_diagonal(char (*arr)[SIZE]) {
  int count_x = 0;
  int count_o = 0;
  int count_zero = 0;
  int check_log = -1;

  // check left diagonal
  for (int i = 0; i < SIZE; i += 1) {
    // one diagonal => resetting of check_log is not necessary

    for (int j = 0; j < SIZE; j += 1) {
      if (i == j) {
        // arr[0][0] => arr[1][1] => arr[2][2] etc
        char current_cell = arr[i][j];

        count_x_o_zero(&count_x, &count_o, &count_zero, &current_cell);
      }
    }

    // check the diagonal
    check_log = check_xo_winner(&count_x, &count_o, &count_zero);

    // ! do not reset count_x, count_o
    // because we're counting all over the matrix!
  }

  if (check_log == -1) {
    puts("Error: incorrect logic in the check_xo_left_diagonal function");
    return check_log;
  }

  return check_log;
}
