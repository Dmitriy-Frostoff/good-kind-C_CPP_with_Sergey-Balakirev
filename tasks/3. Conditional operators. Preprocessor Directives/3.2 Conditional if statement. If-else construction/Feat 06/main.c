/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191260/step/8?unit=1204231}
 *
 */

#include <stdio.h>

int main(void) {
  unsigned int dayOfWeek;

  if (scanf("%u", &dayOfWeek) != 1) {
    printf("not a correct quantity of arguments were given!");

    return 0;
  }

  if (dayOfWeek < 1 || dayOfWeek > 7) {
    printf("неверный номер дня недели\n");

    return 0;
  }

  if (dayOfWeek == 1) {
    printf("понедельник");
  } else if (dayOfWeek == 2) {
    printf("вторник");
  } else if (dayOfWeek == 3) {
    printf("среда");
  } else if (dayOfWeek == 4) {
    printf("четверг");
  } else if (dayOfWeek == 5) {
    printf("пятница");
  } else if (dayOfWeek == 6) {
    printf("суббота");
  } else {
    printf("воскресенье");
  }

  return 0;
}
