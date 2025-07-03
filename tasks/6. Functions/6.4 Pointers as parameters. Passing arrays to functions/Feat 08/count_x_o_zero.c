#include "is_win.h"

/**
 *  @brief count the 'x', 'o' and '0'(zero) in the row, column or diagonal
 *  @note @link{counter_zero} is counted through over the game field and is not
 *    resetted to zero row to row (etc) checking differ to @link{counter_X} and
 *    @link{counter_o}
 *
 *  @note !Impure function! It mutates the original arguments!
 *
 *  @param {const int *} counter_x - pointer to the counter of 'x'
 *  @param {const int *} counter_o - pointer to the counter of 'o'
 *  @param {const int *} counter_zero - pointer to the counter of '0'(zero)
 *
 *  @return {int} - 0, everything is OK
 *  @throw - if pointers are NULL there will be the message in the terminal and
 *    return -1
 *
 *  @example
 *    char arr[3][3] = {
 *      'x',  0,   0
 *       0,  'x', 'o'
 *      'o',  0,  'x'
 *    }
 *    counter_x = 0; counter_o = 0; counter_zero = 0
 *      count_x_o_zero(*counter_x, *counter_o, *counter_zero) => 0
 *      for 'row 1'
 *      counter_x = 1; counter_o = 0; counter_zero = 2
 *
 *      for 'diagonal left'
 *      count_x_o_zero(*counter_x, *counter_o, *counter_zero) => 0
 *      counter_x = 3; counter_o = 0; counter_zero = 2 (it's saved in a check
 *        function till the end)
 */
int count_x_o_zero(int *counter_x, int *counter_o, int *counter_zero,
                   const char *current_value) {
  //  check the pointers
  if (counter_x == NULL || counter_o == NULL) {
    puts("Error: count_x_o_zero func pointers are NULL");
    return -1;
  }

  switch (*current_value) {
  case 0:
    *counter_zero += 1;
    break;
  case CHAR_X:
    *counter_x += 1;
    break;
  case CHAR_O:
    *counter_o += 1;
    break;
  default:
    break;
  }

  return 0;
}
