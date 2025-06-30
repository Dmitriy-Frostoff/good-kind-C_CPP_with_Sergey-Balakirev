/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191281/step/11?unit=1204269}
 *
 */

#include <stdio.h>

#define MAX_BUFF_SIZE 1024

int main(void) {
  unsigned short buff_size;

  if (scanf("%hu", &buff_size) != 1) {
    printf("expected one positive integer!");

    return 0;
  }

  buff_size > MAX_BUFF_SIZE ? buff_size = MAX_BUFF_SIZE : buff_size;

  printf("%u", buff_size);

  return 0;
}
