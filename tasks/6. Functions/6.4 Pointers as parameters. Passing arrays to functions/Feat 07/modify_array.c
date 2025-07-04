#include "./utils.h"

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
