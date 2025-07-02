/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191286/step/5?unit=1204274}
 *
 */

#include <stdio.h>

int main(void) {
  int num;
  int sum = 0;

  do {
    if (scanf("%d", &num) != 1) {
      printf("expected one integer");
      return 0;
    }

    if (num > 0) {
      sum += num;
    }
  } while (num != 13);

  printf("%d", sum);

  return 0;
}
