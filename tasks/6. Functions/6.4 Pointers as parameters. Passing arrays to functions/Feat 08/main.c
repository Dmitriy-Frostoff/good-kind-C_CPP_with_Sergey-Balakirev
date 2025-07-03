/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191305/step/10?unit=1204293}
 *
 */

#include <stdio.h>

#define SIZE 3

#define CHAR_X 'x'
#define CHAR_O 'o'
#define CHAR_ZERO 0

void fill_matrix(char (*arr)[SIZE]);
int is_win(char (*arr)[SIZE]);

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

/**
 *  @brief fill 2d matrix with integers from the input
 *
 *  Scheme: 0 - empty cell, 1 - 'x', 2 - 'o'
 *
 *  @param {char (*)[SIZE]} arr - pointer to the 2d array of integers
 *   {@type char} (SIZE is from #define)
 *
 *  @return {void} - just mutates @link{arr}
 *
 *  @example
 *    const char arr[3][3] = {0}
 *      fill_matrix(arr) =>
 *      INPUT:
 *      1 0 0
 *      0 1 2
 *      2 0 1 =>
 *      arr{
 *        'x'  0   0
 *         0  'x' '0'
 *        '0'  0  'x'
 *      }
 */
void fill_matrix(char (*arr)[SIZE]) {
  // const char CHAR_X = 'x';
  // const char CHAR_O = 'o';

  char *ptr = &arr[0][0];
  int count = 0;

  while (count < SIZE * SIZE && scanf("%hhd", ptr) == 1) {
    switch (*ptr) {
    case CHAR_ZERO:
      break;
    case 1:
      *ptr = CHAR_X;
      break;
    case 2:
      *ptr = CHAR_O;
      break;
    default:
      puts("Error: unknown char. Expected only 0, 1 and 2");
      break;
    }

    ptr += 1;
    count += 1;
  }
}

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

/**
 *  @brief check the game field (2d array) right diagonal for a winner
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
 *      1, 0, 2
 *      0, 2, 2
 *      2, 0, 1
 *    }
 *      check_xo_right_diagonal(arr) => 2
 */
int check_xo_right_diagonal(char (*arr)[SIZE]) {
  int count_x = 0;
  int count_o = 0;
  int count_zero = 0;
  int check_log = -1;

  // check right diagonal
  for (int i = 0; i < SIZE; i += 1) {
    // one diagonal => resetting of check_log is not necessary

    for (int j = SIZE - 1; j >= 0; j -= 1) {
      // arr[0][2] => arr[1][1] => arr[2][0] etc
      char current_cell = arr[i][j];

      count_x_o_zero(&count_x, &count_o, &count_zero, &current_cell);
    }

    // check the diagonal
    check_log = check_xo_winner(&count_x, &count_o, &count_zero);

    // reset counters
    count_x = 0;
    count_o = 0;
  }

  if (check_log == -1) {
    puts("Error: incorrect logic in the check_xo_left_diagonal function");
    return check_log;
  }

  return check_log;
}

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
