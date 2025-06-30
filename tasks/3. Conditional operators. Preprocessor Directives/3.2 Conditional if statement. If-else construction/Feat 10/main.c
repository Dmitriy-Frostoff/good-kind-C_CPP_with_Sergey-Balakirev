/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191260/step/12?unit=1204231}
 *
 */

#include <stdio.h>

int main(void) {
  double len1;
  double len2;
  double len3;

  if (scanf("%lf, %lf, %lf", &len1, &len2, &len3) != 3) {
    printf("must three positive numbers porvieded!");

    return 0;
  }

  if (len1 < len2 + len3 && len2 < len1 + len3 && len3 < len1 + len2) {
    printf("yes");

    return 0;
  }

  printf("no");

  return 0;
}
