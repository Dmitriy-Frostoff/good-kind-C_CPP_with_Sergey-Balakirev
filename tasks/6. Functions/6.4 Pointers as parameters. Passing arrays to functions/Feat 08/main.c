/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191305/step/10?unit=1204293}
 *
 */

#include "config.h"
#include "fill_matrix.h"
#include "is_win.h"

/**
 *  @brief check the tic-tac-toe game field (2d array) for a winner or a draw
 *
 *  Scheme:
 *  game field consist of: 1 - 'x', 2 - 'o', 0 - zero
 *  0 => game is not ended
 *  1 => 'x' win
 *  2 => 'o' win
 *  3 => draw (no more 0 (zeros) and no winner)
 *
 *  @example
 *    INPUT:
 *    1 0 0
 *    0 1 2
 *    2 0 1
 *    OUTPUT:
 *    1
 *
 *    INPUT:
 *    2 0 0
 *    2 1 1
 *    2 0 0
 *    OUTPUT:
 *    2
 *
 *    INPUT:
 *    0 2 0
 *    1 0 1
 *    0 2 0
 *    OUTPUT:
 *    0
 *
 *    INPUT:
 *    1 2 1
 *    2 2 1
 *    2 1 2
 *    OUTPUT:
 *    3
 */
int main(void) {
  char pole[SIZE][SIZE] = {0};

  // fill the @link{pole} array
  fill_matrix(pole);

  // check the game field and print the result
  // @note tests expect the only log from the 'is_win()' execution!
  // do not use any temporary variable in the printf(...) !
  printf("%d", is_win(pole));

  return 0;
}
