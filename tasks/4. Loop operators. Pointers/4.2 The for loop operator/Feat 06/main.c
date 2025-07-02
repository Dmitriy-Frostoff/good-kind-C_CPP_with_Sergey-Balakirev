/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191285/step/8?unit=1204273}
 *
 */

#include <stdio.h>

int main(void) {
  short n;
  short m;

  if (scanf("%hd %hd", &n, &m) != 2 || n > m) {
    printf("expected two integers 'n' and 'm' where n < m");

    return 0;
  }

  for (short currNum = n; currNum <= m; currNum += 1) {
    if (currNum % 2 == 0) {
      printf("%d ", currNum);
    }
  }

  return 0;
}
