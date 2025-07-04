#include "./utils.h"

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
