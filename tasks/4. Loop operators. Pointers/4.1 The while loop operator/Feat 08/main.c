/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191284/step/10?unit=1204272}
 *
 * Among all natural three - digigts numbers find numbers suach that:
 * num % 47 = 6 || num % 53 = 45. Print all the numbers to the console (space
 * separated)
 *
 */

#include <stdio.h>

int main(void) {
  unsigned short num = 100;

  while (num <= 999) {
    if (num % 47 == 6 || num % 53 == 45) {
      printf("%u ", num);
    }

    num += 1;
  }

  return 0;
}
