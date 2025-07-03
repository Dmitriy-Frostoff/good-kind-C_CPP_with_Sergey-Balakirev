#include "is_win.h"

/**
 *  @brief check the game field (2d array) for a winner
 *
 *  It's wrapper function over the checks of game filed @link{arr} .
 *
 *  @note !Impure function and functional princeples violation: under the hood
 *    it uses 'check_xo_rows()', 'check_xo_columns()',
 *    'check_xo_left_diagonal()' and 'check_xo_right_diagonal()' callbacks!
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
 *  @example
 *    char arr[3][3] = {
 *      1, 2, 1
 *      2, 2, 1
 *      2, 1, 2
 *    }
 *      check_xo_right_diagonal(arr) => 3
 */
int is_win(char (*arr)[SIZE]) {
  // possible values: 0 | 1 | 2 | 3
  int game_state = 0;

  // check rows
  game_state = check_xo_rows(arr);

  if (game_state != 0) {
    return game_state;
  }

  // check columns
  game_state = check_xo_columns(arr);

  if (game_state != 0) {
    return game_state;
  }

  // check left diagonal
  game_state = check_xo_left_diagonal(arr);

  if (game_state != 0) {
    return game_state;
  }

  // check right diagonal
  game_state = check_xo_right_diagonal(arr);

  if (game_state != 0) {
    return game_state;
  }

  // i.e. game_state == 0, game haven't been finished
  return game_state;
}
