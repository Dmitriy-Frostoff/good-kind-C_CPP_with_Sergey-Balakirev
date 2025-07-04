#include "./utils.h"

/**
 *  @brief transpose 2d matrix
 *
 *  @param {short (*)[SIZE]) arr - pointer to the 2d array of short integers
 *   (SIZE is from #define)
 *
 *  @return {void} - just mutates @link{arr}
 *
 *  @example
 *    const short arr[4][4] = {
 *      1, 2, 3, 4
 *      5, 6, 7, 8
 *      9, 8, 7, 6
 *      5, 4, 3, 2
 *    }
 *      transpose(arr) => void
 *      arr[4][4]{
 *        1, 5, 9, 5
 *        2, 6, 8, 4
 *        3, 7, 7, 3
 *        4, 8, 6, 2
 *      }
 */
void transpose(short (*arr)[SIZE]) {
  for (int i = 0; i < SIZE; i += 1) {
    for (int j = i; j < SIZE; j += 1) {
      short temp = arr[j][i];
      arr[j][i] = arr[i][j];
      arr[i][j] = temp;
    }
  }
}
