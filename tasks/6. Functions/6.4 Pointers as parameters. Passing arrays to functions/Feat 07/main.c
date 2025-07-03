/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191305/step/9?unit=1204293}
 *
 */

#include <stdio.h>

#define SIZE 3

void fill_matrix(char (*arr)[SIZE]);
void modify_array(char (*arr)[SIZE]);
void print_maxtrix(const char (*arr)[SIZE]);
void show_pole(char (*arr)[SIZE]);

int main(void) {
  char pole[SIZE][SIZE] = {0};

  // fill 'matrix' 2d array
  fill_matrix(pole);

  // modify and print to the console @link{pole} array elems
  show_pole(pole);

  return 0;
}

/**
 *  @brief fill 2d matrix with integers from the input
 *
 *  @param {char *} (*arr)[SIZE] - pointer to the 2d array of integers
 *   @type{char} (SIZE is from #define)
 *
 *  @return {void} - just mutates @link{(*arr)[SIZE]}
 *
 *  @example
 *    arr[3][3] = {0}
 *      fill_matrix(arr) =>
 *      0 1 0
 *      2 0 2
 *      1 0 0 =>
 *      arr{
 *        0 1 0
 *        2 0 2
 *        1 0 0
 *      }
 */
void fill_matrix(char (*arr)[SIZE]) {
  char *ptr = &arr[0][0];
  int count = 0;

  while (count < SIZE * SIZE && scanf("%hhd", ptr) == 1) {
    ptr += 1;
    count += 1;
  }
}

/**
 *  @brief modify the 2d array over the scheme
 *
 *  scheme: 0 => '#', 1 => 'x', 2 => 'o'
 *
 *  @param {char *} (*arr)[SIZE] - 2d array of integers @type{char}
 *
 *  @return {void} - just mutates @link{(*arr)[SIZE]}
 *
 *  @example
 *    arr[3][3] = {
 *      0, 1, 0
 *      2, 0, 2
 *      1, 0, 0
 *    }
 *      modify_array(arr) => void
 *      arr[3][3] {
 *        #, x, #
 *        o, #, o
 *        x, #, #
 *      }
 */
void modify_array(char (*arr)[SIZE]) {
  const char CHAR_X = 'x';
  const char CHAR_ZERO = 'o';
  const char CHAR_SHARP = '#';

  for (int i = 0; i < SIZE; i += 1) {
    for (int j = 0; j < SIZE; j += 1) {
      char current_elem = arr[i][j];

      switch (current_elem) {
      case 0:
        arr[i][j] = CHAR_SHARP;
        break;
      case 1:
        arr[i][j] = CHAR_X;
        break;
      case 2:
        arr[i][j] = CHAR_ZERO;
        break;
      default:
        break;
      }
    }
  }
}

/**
 *  @brief print to the console 2d matrix
 *
 *  @param {char *} (*arr)[SIZE] - pointer to the 2d array of integers
 *   @type{char} (SIZE is from #define)
 *
 *  @return {void} - just prints @link{(*arr)[SIZE]}
 *
 *  @example
 *    arr[3][3]{
 *        '#, x, #'
 *        'o, #, o'
 *        'x, #, #'
 *      }
 *      print_maxtrix(arr) => void
 *      >>>
 *      # x #
 *      o # o
 *      x # #
 */
void print_maxtrix(const char (*arr)[SIZE]) {
  for (int i = 0; i < SIZE; i += 1) {
    for (int j = 0; j < SIZE; j += 1) {
      if (j == SIZE - 1) {
        printf("%c\n", arr[i][j]);
        break;
      }
      printf("%c ", arr[i][j]);
    }
  }
}

/**
 *  @brief modify and print to the console 2d array
 *  @note !Impure function! Uses functions that are not declared as callbacks!
 *  TODO! Rewrite with callbacks usage for @link{modify_array} and
 *    @link{print_maxtrix} functions!!!
 *
 *  @param {char *} (*arr)[SIZE] - pointer to the 2d array of integers
 *   @type{char} (SIZE is from #define)
 *
 *  @return {void} - just modifies and print to the console array values
 *
 *  @example
 *    arr[3][3] = {0}
 *      show_pole(arr) => void
 *      arr{
 *        0 1 0
 *        2 0 2
 *        1 0 0
 *      } =>
 *      arr[3][3]{
 *        '#, x, #'
 *        'o, #, o'
 *        'x, #, #'
 *      }
 *      >>>
 *      # x #
 *      o # o
 *      x # #
 */
void show_pole(char (*arr)[SIZE]) {
  // modify 2d array via template: 1 => 'x', 2 => 'o', 0 => '#'
  modify_array(arr);

  // print 2d array to the console
  print_maxtrix(arr);
}
