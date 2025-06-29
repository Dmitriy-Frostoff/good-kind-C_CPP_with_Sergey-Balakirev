/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191247/step/7?thread=solutions&unit=1204218}
 *
 * The program must use the 'printf()' function to print all declared variables
 * (in the order they are declared) in one line separated by a space. Print the
 * real number to the nearest ten thousandths (4 decimal places).
 *
 */
#include <stdio.h>

int main(void) {
  unsigned height = 12345012;
  long long dist = 1234567890LL;
  long double weight = 45.7845;

  printf("%u %lld %.4Lf", height, dist, weight);

  return 0;
}
