/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191295/step/7?unit=1204283}
 *
 */

#include <stdbool.h>
#include <stdio.h>

#define TOTAL 20

int main(void) {
  short pows[TOTAL] = {0};
  int count = 0;
  int pows_length = sizeof(pows) / sizeof(*pows);
  bool isEvenCheckDone = false;

  while (count < pows_length && scanf("%hd", &pows[count]) == 1) {
    count++;
  }

  /**
   *  @example
   *    pows{1, 3, 5, 7, 8, 4, 3, 2, 1, 0 x 11} =>
   *      pows{1, 3, 5, 7, 4, 3, 2, 1, 0 x 12}
   *      remove first num that num % 2 == 0 => 8 % 2 == 0
   *        and move nums to the left (to indexof num = 8)
   *
   *    pows{1, 3, 5, 7, 9, 11, 13, 15, 1, 0 x 11} =>
   *      pows{1, 3, 5, 7, 9, 11, 13, 15, 1, 0 x 11}
   *      nothing to remove
   */
  for (int i = 0; i < count; i += 1) {
    if (pows[i] % 2 == 0 && !isEvenCheckDone) {
      isEvenCheckDone = true;
      // one num will be removed
      count -= 1;

      for (int j = i; j < count; j += 1) {
        pows[j] = pows[j + 1];
      }
    }
  }

  for (int i = 0; i < count; i += 1) {
    printf("%d ", pows[i]);
  }

  return 0;
}
