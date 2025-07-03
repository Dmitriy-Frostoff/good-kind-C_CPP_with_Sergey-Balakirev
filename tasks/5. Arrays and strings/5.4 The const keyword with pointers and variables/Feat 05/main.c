/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191294/step/7?unit=1204282}
 *
 */

#include <stdio.h>

#define AR_LENGTH 100

/**
 * @note
 *    expected only max 100 integers at input!
 */
int main(void) {
  int ar[AR_LENGTH];
  int *const PTR_AR = ar;
  int input_num = 0;

  /**
   * @example
   *    1 6 4 2 0 -100 496 3 5 78 101 102 103 and ar[] =>
   *      input_num = 78 ? return : ar{[i] = input_num} =>
   *        ar[1, 6, 4, 2, 0, -100, 496, 3, 5]
   */
  for (unsigned char i = 0; i < AR_LENGTH; i += 1) {
    if (scanf("%d ", &input_num) != 1) {
      printf("expected one integer");
      return 0;
    }

    if (input_num != 78) {
      PTR_AR[i] = input_num;
      printf("%d ", PTR_AR[i]);
      continue;
    }

    return 0;
  }

  printf("expected max 100 integers");

  return 0;
}
