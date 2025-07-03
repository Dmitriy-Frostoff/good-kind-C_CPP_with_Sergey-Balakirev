#include "fill_matrix.h"

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
