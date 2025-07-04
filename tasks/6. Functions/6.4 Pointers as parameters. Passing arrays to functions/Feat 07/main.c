/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191305/step/9?unit=1204293}
 *
 */

#include "./config.h"
#include "./utils.h"

int main(void) {
  char pole[SIZE][SIZE] = {0};

  // fill 'matrix' 2d array
  fill_matrix(pole);

  // modify and print to the console @link{pole} array elems
  show_pole(pole);

  return 0;
}
