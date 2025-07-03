/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191296/step/11?unit=1204284}
 *
 * Write a program in which 12 "mines" are randomly placed on a two-dimensional
 * 10 x 10 playing field so that they do not touch each other (there should be
 * no other mines around the cage with the mine). The playing field should be
 * represented by a two-dimensional array named 'pg', type char, and size of 10
 * x 10. Empty cells (without mines) must take the value 0, and cells with mines
 * are marked with the symbol '*'.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10
#define MINES 12

int main(void) {
  char pg[SIZE][SIZE] = {0};
  int mines_count = 0;
  // set seed as SIZE
  srand(time(NULL));
  int coord_i = 0;
  int coord_j = 0;

  // set mines over the field SIZE x SIZE
  // every mine is not one square close to another!
  while (mines_count < MINES) {
    // set i and j in range [0; 10)
    coord_i = rand() % SIZE;
    coord_j = rand() % SIZE;

    /**
     * i - 1, j     | i - 1, j | i - 1, j + 1
     * i    , j - 1 | i , j    | i    , j + 1
     * i + 1, j - 1 | i + 1, j | i + 1, j + 1
     */

    // check left upper corner
    if ((coord_i == 0 && coord_j == 0) && (pg[coord_i][coord_j] != '*') &&
        (pg[coord_i][coord_j + 1] != '*') &&
        (pg[coord_i + 1][coord_j] != '*') &&
        (pg[coord_i + 1][coord_j + 1] != '*')) {
      pg[coord_i][coord_j] = '*';
      mines_count += 1;
      continue;
    }

    // check right upper corner
    if ((coord_i == 0 && coord_j == SIZE - 1) &&
        (pg[coord_i][coord_j - 1] != '*') && (pg[coord_i][coord_j] != '*') &&
        (pg[coord_i + 1][coord_j - 1] != '*') &&
        (pg[coord_i + 1][coord_j] != '*')) {
      pg[coord_i][coord_j] = '*';
      mines_count += 1;
      continue;
    }

    // check bottom left corner
    if ((coord_i == SIZE - 1 && coord_j == 0) &&
        (pg[coord_i - 1][coord_j] != '*') &&
        (pg[coord_i - 1][coord_j + 1] != '*') &&
        (pg[coord_i][coord_j] != '*') && (pg[coord_i][coord_j + 1] != '*')) {
      pg[coord_i][coord_j] = '*';
      mines_count += 1;
      continue;
    }

    // check bottom right corner
    if ((coord_i == SIZE - 1 && coord_j == SIZE - 1) &&
        (pg[coord_i - 1][coord_j - 1] != '*') &&
        (pg[coord_i - 1][coord_j] != '*') &&
        (pg[coord_i][coord_j - 1] != '*') && (pg[coord_i][coord_j] != '*')) {
      pg[coord_i][coord_j] = '*';
      mines_count += 1;
      continue;
    }

    //  boundary case coord_i = 0 (first row)
    if ((coord_i == 0 && coord_j - 1 >= 0 && coord_j + 1 <= SIZE) &&
        (pg[coord_i][coord_j - 1] != '*') && (pg[coord_i][coord_j] != '*') &&
        (pg[coord_i][coord_j + 1] != '*') &&
        (pg[coord_i + 1][coord_j - 1] != '*') &&
        (pg[coord_i + 1][coord_j] != '*') &&
        (pg[coord_i + 1][coord_j + 1] != '*')) {
      pg[coord_i][coord_j] = '*';
      mines_count += 1;
      continue;
    }

    //  boundary cases coord_i = SIZE - 1 (last row)
    if ((coord_i == SIZE - 1 && coord_j - 1 >= 0 && coord_j + 1 <= SIZE) &&
        (pg[coord_i - 1][coord_j - 1] != '*') &&
        (pg[coord_i - 1][coord_j] != '*') &&
        (pg[coord_i - 1][coord_j + 1] != '*') &&
        (pg[coord_i][coord_j - 1] != '*') && (pg[coord_i][coord_j] != '*') &&
        (pg[coord_i][coord_j + 1] != '*')) {
      pg[coord_i][coord_j] = '*';
      mines_count += 1;
      continue;
    }

    //  boundary case coord_j = 0 (first column)
    if ((coord_j == 0 && coord_i - 1 >= 0 && coord_i + 1 <= SIZE) &&
        (pg[coord_i - 1][coord_j] != '*') && (pg[coord_i][coord_j] != '*') &&
        (pg[coord_i + 1][coord_j] != '*') &&
        (pg[coord_i - 1][coord_j + 1] != '*') &&
        (pg[coord_i][coord_j + 1] != '*') &&
        (pg[coord_i + 1][coord_j + 1] != '*')) {
      pg[coord_i][coord_j] = '*';
      mines_count += 1;
      continue;
    }

    //  boundary cases coord_j = SIZE - 1 (last column)
    if ((coord_j == SIZE - 1 && coord_i - 1 >= 0 && coord_i + 1 <= SIZE) &&
        (pg[coord_i - 1][coord_j - 1] != '*') &&
        (pg[coord_i][coord_j - 1] != '*') &&
        (pg[coord_i + 1][coord_j - 1] != '*') &&
        (pg[coord_i - 1][coord_j] != '*') && (pg[coord_i][coord_j] != '*') &&
        (pg[coord_i + 1][coord_j + 1] != '*')) {
      pg[coord_i][coord_j] = '*';
      mines_count += 1;
      continue;
    }

    // check the middle square and squares around it
    if (
        // check the line above pg[i][j] => pg[i - 1][j]
        (((coord_i - 1 >= 0 && coord_j - 1 >= 0 && coord_j + 1 <= SIZE) &&
          (pg[coord_i - 1][coord_j - 1] != '*') &&
          (pg[coord_i - 1][coord_j] != '*') &&
          (pg[coord_i - 1][coord_j + 1] != '*')) &&
         // check the line pg[i][j] => pg[i][j]
         ((coord_i > 0 && coord_i < SIZE - 1 && coord_j - 1 >= 0 &&
           coord_j + 1 <= SIZE) &&
          (pg[coord_i][coord_j - 1] != '*') && (pg[coord_i][coord_j] != '*') &&
          (pg[coord_i][coord_j + 1] != '*')) &&
         // check the line beneath pg[i][j] => pg[i + 1][j]
         ((coord_i + 1 <= SIZE && coord_j - 1 >= 0 && coord_j + 1 <= SIZE) &&
          (pg[coord_i + 1][coord_j - 1] != '*') &&
          (pg[coord_i + 1][coord_j] != '*') &&
          (pg[coord_i + 1][coord_j + 1] != '*')))

    ) {
      pg[coord_i][coord_j] = '*';
      mines_count += 1;
    }
  }

  // fill the rest squares of field SIZE x SIZE with 0
  for (int i = 0; i < SIZE; i += 1) {
    for (int j = 0; j < SIZE; j += 1) {
      if (pg[i][j] != '*') {
        pg[i][j] = 0;
      }
    }
  }

  /**
   * для тестирования
   * (не убирать и должна идти непосредственно перед return 0)
   */
  __assert_verify_pg(pg);

  return 0;
}
