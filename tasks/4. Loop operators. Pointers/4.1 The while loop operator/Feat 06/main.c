/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191284/step/8?unit=1204272}
 *
 */

#include <stdio.h>

int main() {
  unsigned short fibonacciPrevElem = 0;
  unsigned short fibonacciCurrElem = 1;
  unsigned short fibonacciNextElem;
  unsigned short fibonacciElemIndex = 0;
  unsigned short fibonacciMaxElem;

  /**
   * fibonacciElemIndex 0 => 1
   * fibonacciElemIndex 1 => 1
   * fibonacciElemIndex 2 => 2
   */
  if (scanf("%hu", &fibonacciMaxElem) != 1) {
    printf("expected one positive integer");

    return 0;
  }

  while (fibonacciElemIndex < fibonacciMaxElem) {
    printf("%u ", fibonacciCurrElem);

    fibonacciNextElem = fibonacciPrevElem + fibonacciCurrElem;

    fibonacciPrevElem = fibonacciCurrElem;
    fibonacciCurrElem = fibonacciNextElem;
    fibonacciElemIndex += 1;
  }

  return 0;
}
