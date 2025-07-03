#include "is_win.h"

/**
 *  @brief check for a winner or a draw in the tic - tac - toe game
 *
 *  @param {const int *} counter_x - pointer to the counter of 'x'
 *  @param {const int *} counter_o - pointer to the counter of 'o'
 *  @param {const int *} counter_zero - pointer to the counter of '0'(zero)
 *
 *  @return {int} - 1, 'x' have won
 *  @return {int} - 2, 'o' have won
 *  @return {int} - 3, 'draw' happend (not've got the winner and no more
 *    '0'(zeros))
 *  @return {int} - 0, game hadn't been finished (there're '0'zeros on the
 *    game field)
 *  @throw - if pointers are NULL there will be the message in the terminal and
 *    return -1
 *
 *  @example
 *    const 2d_array[3][3] => if counter == 3 => winner
 *    check_xo_winner(3, 2, 1) => 1, 'x' won
 *    check_xo_winner(2, 3, 1) => 2, 'o' won
 *    check_xo_winner(2, 2, 0) => 3, 'draw'
 *    check_xo_winner(1, 0, 8) => 0, game is not finished
 */
int check_xo_winner(const int *counter_x, const int *counter_o,
                    const int *counter_zero) {
  const int CELL_WINNER_COUNT = SIZE;

  //  check the pointers
  if (counter_x == NULL || counter_o == NULL || counter_zero == NULL) {
    puts("Error: check_xo_winner func pointers are NULL");
    return -1;
  }

  // check winner if exist (counter == CELL_WINNER_COUNT ? => winner)
  // check for 'x' winner
  if ((*counter_x == CELL_WINNER_COUNT) && (*counter_o != CELL_WINNER_COUNT)) {
    return 1;
  }

  // check for 'o' winner
  if ((*counter_o == CELL_WINNER_COUNT) && (*counter_x != CELL_WINNER_COUNT)) {
    return 2;
  }

  // check for draw
  if (((*counter_o == *counter_x) && (*counter_x == CELL_WINNER_COUNT)) ||
      *counter_zero == 0) {
    return 3;
  }

  // game haven't been ended
  return 0;
}
