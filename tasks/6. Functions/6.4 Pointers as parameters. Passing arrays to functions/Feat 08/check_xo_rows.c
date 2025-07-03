#include "is_win.h"

/**
 *  @brief check the game field (2d array) rows for a winner or a draw
 *
 *  @note !Impure function and functional princeples violation: under the hood
 *    it uses 'count_x_o_zero()' and 'check_xo_winner()' callbacks!
 *
 *  @note Only this function checks for a 'draw' properly, because it steps
 *    through all the entire @link{arr} and counts the '0' (zeros)
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
 *      1, 1, 1
 *      2, 1, 1
 *      2, 0, 0
 *    }
 *      check_xo_rows(arr) => 1
 */
int check_xo_rows(char (*arr)[SIZE]) {
  int count_x = 0;
  int count_o = 0;
  int count_zero = 0;
  int check_log = -1;

  // check rows
  for (int i = 0; i < SIZE; i += 1) {
    // reset check_log
    check_log = -1;

    for (int j = 0; j < SIZE; j += 1) {
      // arr[0][0] => arr[0][1] => arr[0][2] etc
      char current_cell = arr[i][j];

      count_x_o_zero(&count_x, &count_o, &count_zero, &current_cell);
    }

    // check the row
    check_log = check_xo_winner(&count_x, &count_o, &count_zero);

    // 'x' or 'o' have won or 'draw' happened ? => return log
    if (check_log != 0) {
      return check_log;
    }

    // reset counters
    count_x = 0;
    count_o = 0;
  }

  if (check_log == -1) {
    puts("Error: incorrect logic in the check_xo_rows function");
    return check_log;
  }

  // all cells are 'x' or 'o' and no '0'(zero) ? => 'draw'
  check_log = check_xo_winner(&count_x, &count_o, &count_zero);

  return check_log;
}
