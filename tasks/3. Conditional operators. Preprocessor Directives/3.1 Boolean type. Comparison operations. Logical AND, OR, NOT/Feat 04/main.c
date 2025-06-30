/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191258/step/6?unit=1204229}
 *
 */

#include <stdbool.h>
#include <stdio.h>

int main(void) {
  int inputValue;
  int isMultipleOf5;

  scanf("%d", &inputValue);

  // check that inputValue is multiple of 5
  isMultipleOf5 = inputValue % 5 == 0;

  isMultipleOf5 &&printf("%d\n", isMultipleOf5 + 99);
  !isMultipleOf5 &&printf("%d\n", isMultipleOf5);

  return 0;
}
