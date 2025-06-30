/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191262/step/6?unit=1204233}
 *
 */

#include <stdio.h>

int main(void) {
  unsigned short len1;
  unsigned short len2;

  if (scanf("%hu; %hu", &len1, &len2) != 2) {
    printf("expected two positive integers!");

    return 0;
  }

  printf("%s", len1 == len2 ? "square" : "rectangle");

  return 0;
}
