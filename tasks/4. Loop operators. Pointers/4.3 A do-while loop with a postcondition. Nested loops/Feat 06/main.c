/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191286/step/8?unit=1204274}
 *
 */

#include <stdio.h>

int main(void) {
  unsigned char n;

  if (scanf("%hhu", &n) != 1 || n <= 0) {
    printf("expected one positive integer");
    return 0;
  }

  // *\n is printed always, but * are optional (additional)
  /**
   * @example
   *   rowCount 0 => 0 of * and *\n => *\n
   *   rowCount 1 => 1 of * and *\n => **\n
   *   rowCount 6 (7 of * expected) => 6 of * and *\n => *******\n
   */
  for (unsigned char rowCount = 0; rowCount < n; rowCount += 1) {
    for (unsigned char addAstPerRowCount = 1; addAstPerRowCount <= rowCount;
         addAstPerRowCount += 1) {
      printf("*");
    }
    printf("*\n");
  }

  return 0;
}
