/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191260/step/6?unit=1204231}
 *
 */

#include <stdio.h>

int main(void) {
  int num1;
  int num2;

  if (scanf("%d %d", &num1, &num2) != 2) {
    printf("must be given two numbers!");

    return 0;
  }

  if (num1 == num2) {
    printf("%d", num1);
  } else if (num1 < num2) {
    printf("%d %d", num1, num2);
  } else {
    printf("%d %d", num2, num1);
  }

  return 0;
}
