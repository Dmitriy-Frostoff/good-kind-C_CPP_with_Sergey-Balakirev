/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191260/step/11?unit=1204231}
 *
 */

#include <stdio.h>

int main(void) {
  double num1;
  double num2;
  double num3;

  if (scanf("%lf, %lf, %lf", &num1, &num2, &num3) != 3) {
    printf("three real numbers must be inputed!");

    return 0;
  }

  if (num1 <= num2 && num1 <= num3) {
    printf("%.2f", num1);
  } else if (num2 <= num1 && num2 <= num3) {
    printf("%.2f", num2);
  } else {
    printf("%.2f", num3);
  }

  return 0;
}
