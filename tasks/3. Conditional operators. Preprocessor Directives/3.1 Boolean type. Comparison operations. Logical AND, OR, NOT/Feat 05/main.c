/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191258/step/7?unit=1204229}
 *
 */

#include <stdbool.h>
#include <stdio.h>

int main(void) {
  /**
   * inputNum is a real number! but scanf with %d will read only integer part!
   */
  short inputNum;
  bool isMultipleOf5;

  scanf("%d", &inputNum);

  isMultipleOf5 = inputNum % 5 == 0;

  printf("%d", isMultipleOf5);

  return 0;
}
