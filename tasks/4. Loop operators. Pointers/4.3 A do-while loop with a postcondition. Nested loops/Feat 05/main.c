/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191286/step/7?unit=1204274}
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  unsigned short x;
  unsigned short a = 1;
  unsigned short b = 1000;
  unsigned short m;

  if (scanf("%hu", &x) != 1 || x <= 0) {
    printf("expected one positive integer in range [1; 1000]");
    return 0;
  }

  // create new random number every time
  srand(time(NULL));

  do {
    // to set m in range [a; b)
    m = rand() % b + a;

    if (m == x) {
      printf("%u", m);
      return 0;
    }

    if (m < x) {
      a = m;
    }

    if (m > x) {
      b = m;
    }
  } while (m != x);

  return 0;
}
