/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191285/step/11?unit=1204273}
 *
 */

#include <stdio.h>

int main(void) {
  unsigned short num;

  // check that first num is 0 => 0 and EOF
  if (scanf("%hu", &num) == 1 && num == 0) {
    printf("%u", num);
    return 0;
  }

  while (num != 0) {
    // print current got num from first scanf
    printf("%u", num);

    if (scanf("%hu", &num) != 1 || num < 0) {
      printf("expeted one positive digit");
      return 0;
    }
  }

  return 0;
}
