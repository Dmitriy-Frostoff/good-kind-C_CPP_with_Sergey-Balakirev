#include "is_win.h"

/**
 *  @brief check the game field (2d array) columns for a winner
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
 *      2, 0, 0
 *      2, 1, 1
 *      2, 0, 0
 *    }
 *      check_xo_columns(arr) => 2
 */
int check_xo_columns(char (*arr)[SIZE]) {
  int count_x = 0;
  int count_o = 0;
  int count_zero = 0;
  int check_log = -1;

  // check columns
  for (int i = 0; i < SIZE; i += 1) {
    // reset check_log
    check_log = -1;

    for (int j = 0; j < SIZE; j += 1) {
      // arr[0][0] => arr[1][0] => arr[2][0] etc
      char current_cell = arr[j][i];

      count_x_o_zero(&count_x, &count_o, &count_zero, &current_cell);
    }

    // check the column
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
    puts("Error: incorrect logic in the check_xo_columns function");
    return check_log;
  }

  return check_log;
}
