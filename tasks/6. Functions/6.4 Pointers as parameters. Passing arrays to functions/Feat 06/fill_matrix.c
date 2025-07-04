#include "./utils.h"

/**
 *  @brief fill 2d matrix with integers from the input
 *
 *  @param {short (*)[SIZE]} arr - pointer to the 2d array of short integers
 *   (SIZE is from #define)
 *
 *  @return {void} - just mutates @link{arr}
 *
 *  @example
 *    const short arr[4][4] = {0}
 *      fill_matrix(arr) =>
 *      INPUT:
 *      1 2 3 4
 *      5 6 7 8
 *      9 8 7 6
 *      5 4 3 2 =>
 *      arr{
 *        1, 2, 3, 4
 *        5, 6, 7, 8
 *        9, 8, 7, 6
 *        5, 4, 3, 2
 *      }
 */
void fill_matrix(short (*arr)[SIZE]) {
  short *ptr = &arr[0][0];
  int count = 0;

  while (count < SIZE * SIZE && scanf("%hd", ptr) == 1) {
    ptr += 1;
    count += 1;
  }
}
