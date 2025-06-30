/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191262/step/9?unit=1204233}
 *
 */

#include <stdio.h>

int main(void) {
  unsigned int len1;
  unsigned int len2;
  unsigned int len3;

  if (scanf("%u %u %u", &len1, &len2, &len3) != 3) {
    printf("expected three postive integers!");

    return 0;
  }

  printf("%s",
         len1 < len2 + len3
             ? (len2 < len1 + len3 ? (len3 < len1 + len2 ? "yes" : "no") : "no")
             : "no");

  return 0;
}
