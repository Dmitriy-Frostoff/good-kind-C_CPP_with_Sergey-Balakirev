/**
 *  The task description is at
 *  @link{https://stepik.org/lesson/1191309/step/7?unit=1204297}
 *
 *  Write 'sumf' function with variadic arguments that sum every arg if
 *  correspondent char in the string (given as first param of 'sumf') is '+'.
 *              indexes 012345   0  1  2  3  4  5
 *  I.e. logic is sumf("++ + +", 1, 2, 3, 4, 5, 6) => 1 + 2 + 4 + 6 => 13
 *
 */

#include "./config.h"
#include "./utils.h"

int main(void) {
  double res = sumf("++ + +", 1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  printf("%.2f ", res);

  return 0;
}
