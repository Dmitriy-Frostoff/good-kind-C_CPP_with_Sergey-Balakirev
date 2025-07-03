/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191305/step/8?unit=1204293}
 *
 */

#include <stdio.h>

#define SIZE 4

void fill_matrix(short (*arr)[SIZE]);
void transpose(short (*arr)[SIZE]);
void print_matrix(const short (*arr)[SIZE]);

/**
 *  @brief fill the 2d matrix from the input, transpose it and print to the
 *  terminal
 *
 *  @example
 *    1 2 3 4
 *    5 6 7 8
 *    9 8 7 6
 *    5 4 3 2 =>
 *    OUTPUT: >>>
 *    1 5 9 5
 *    2 6 8 4
 *    3 7 7 3
 *    4 8 6 2
 */
int main(void) {
  short matrix[SIZE][SIZE] = {0};

  // fill 'matrix' array
  fill_matrix(matrix);

  // transpose matrix
  transpose(matrix);

  // print transposed matrix
  print_matrix(matrix);

  return 0;
}

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
