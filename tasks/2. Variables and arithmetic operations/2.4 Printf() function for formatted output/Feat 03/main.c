/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191247/step/5?unit=1204218}
 *
 * The program should output all declared variables (in the order of their
 * declaration) from a new line. However, there should be no gaps in the output.
 * Use the 'printf()' function for this formatted output. A symbolic variable
 * must be output as a real character with no precision limit.
 *
 */
#include <stdio.h>

int main(void) {
  char byte = 65;
  unsigned short height = 1055;
  int distance = 1000000;
  float pi = 3.1415f;

  printf("%c\n%u\n%d\n%f\n", byte, height, distance, pi);

  return 0;
}
