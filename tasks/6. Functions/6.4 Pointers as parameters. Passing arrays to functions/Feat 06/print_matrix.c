#include "./utils.h"

/**
 *  @brief print to the console 2d matrix
 *
 *  @param {const short (*)[SIZE]} arr - pointer to the 2d array of short
 *  integers (SIZE is from #define)
 *
 *  @return {void} - just prints @link{arr}
 *
 *  @example
 *    const short arr[4][4]{
 *        1, 5, 9, 5
 *        2, 6, 8, 4
 *        3, 7, 7, 3
 *        4, 8, 6, 2
 *      }
 *      print_matrix(arr) => void
 *      OUTPUT:>>>
 *      1 5 9 5
 *      2 6 8 4
 *      3 7 7 3
 *      4 8 6 2
 */
void print_matrix(const short (*arr)[SIZE]) {
  for (int i = 0; i < SIZE; i += 1) {
    for (int j = 0; j < SIZE; j += 1) {
      if (j == SIZE - 1) {
        printf("%hd\n", arr[i][j]);
        break;
      }
      printf("%hd ", arr[i][j]);
    }
  }
}
