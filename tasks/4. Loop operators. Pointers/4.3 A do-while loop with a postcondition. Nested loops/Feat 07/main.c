/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191286/step/9?unit=1204274}
 *
 */

#include <stdio.h>

#define WhiteSpaceASCIICode 32

int main(void) {
  unsigned char n;

  if (scanf("%hhu", &n) != 1 || n <= 0) {
    printf("expected one positive integer");
    return 0;
  }

  // every row is consist of spaces and *. Formula for the quantity of elems is:
  // 2 * n - 1 => e.g. n = 7 => 2 * 7 - 1 => 13 characters per row (max)

  // quantity of white spaces => row0 => 6
  // quantity of white spaces => row1 => 5
  // quantity of white spaces => row2 => 4
  // quantity of white spaces => row5 => 1
  // quantity of white spaces => row6 => 0

  // quantity of * => row0 => 1
  // quantity of * => row1 => 3
  // quantity of * => row2 => 5
  // quantity of * => row5 => 7
  // quantity of * => row6 => 13

  // '*\n' always present in the end of line, so only
  // quantity of white spaces and additional * and are differ (* -> grow,
  // wspaces -> reduce)

  for (unsigned char rowCount = 0; rowCount < n; rowCount += 1) {
    /**
     * @example
     *    for n = 7
     *    row 0 => spaceCount = 6
     *    row 1 => spaceCount = 5
     *    row 6 => spaceCount = 0
     */
    for (unsigned char spaceCount = n - 1; spaceCount > rowCount;
         spaceCount -= 1) {
      printf("%c", WhiteSpaceASCIICode);
    }

    /**
     * @example
     *    for n = 7
     *    row 0 => addAstCount = 0
     *    row 1 => addAstCount = 2
     *    row 2 => addAstCount = 4
     *    row 6 => addAstCount = 6
     */
    for (unsigned char addAstCount = 1; addAstCount < rowCount * 2 + 1;
         addAstCount += 1) {
      printf("*");
    }

    printf("*\n");
  }

  return 0;
}
