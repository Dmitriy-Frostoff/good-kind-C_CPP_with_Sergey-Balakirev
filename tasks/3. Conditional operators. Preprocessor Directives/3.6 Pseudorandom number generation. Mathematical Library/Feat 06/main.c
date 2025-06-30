/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191266/step/8?unit=1204237}
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  unsigned short r1;
  unsigned short r2;
  unsigned short r3;
  unsigned short r4;
  unsigned short r5;

  srand(time(NULL));

  r1 = rand();
  r2 = rand();
  r3 = rand();
  r4 = rand();
  r5 = rand();

  __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно
                   // идти непосредственно перед return 0)
      return 0;
}
