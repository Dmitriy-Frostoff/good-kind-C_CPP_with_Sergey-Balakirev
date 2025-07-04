#include "./utils.h"

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
