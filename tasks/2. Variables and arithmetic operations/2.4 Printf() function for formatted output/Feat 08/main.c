/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191247/step/10?unit=1204218}
 *
 * The program must use the 'printf()' function to output the value of a real
 * variable with an accuracy of one thousandth (three decimal places).
 *
 */
#include <stdio.h>

int main(void) {
  double d = 546e-3;

  printf("%.3f", d);

  return 0;
}
