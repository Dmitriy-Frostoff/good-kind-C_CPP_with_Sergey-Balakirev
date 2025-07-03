/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191295/step/8?unit=1204283}
 *
 */

#include <stdio.h>

#define TOTAL 20

int main(void) {
  short pows[TOTAL] = {0};
  int count = 0;
  int pows_length = sizeof(pows) / sizeof(*pows);

  while (count < pows_length && scanf("%hd", &pows[count]) == 1) {
    count += 1;
  }

  /**
   *  @example
   *    {1, 2, 3, 4, 5, 6, 7, 8, 9, 10} =>
   *      {1, 2, 4, 5, 7, 8, 10}
   *      remove nums that num % 3 == 0 => 3(...6, 9) % 3 == 0
   *
   *    {1, 2, 4, 5, 7, 8, 10} =>
   *      {1, 2, 4, 5, 7, 8, 10}
   *      nothing to remove
   */
  for (int i = 0; i < count; i += 1) {
    if (pows[i] % 3 == 0) {
      // remove one num from pows
      count -= 1;

      /**
       * @example
       *    j = 2 and pows{1, 2, 3, 4} => pows{1, 2, 4, 0}
       */
      for (int j = i; j < count; j += 1) {
        pows[j] = pows[j + 1];
      }

      if (pows[i] % 3 == 0) {
        // reduce index to check moved num to current index
        // {1, 2, 3, 6, 7} => before pows[i = 2] => 3
        // after pows[i = 2] => 6 =>
        // {1, 2, 6, 7}
        i -= 1;
      }
    }
  }

  for (int i = 0; i < count; i += 1) {
    printf("%d ", pows[i]);
  }

  return 0;
}
