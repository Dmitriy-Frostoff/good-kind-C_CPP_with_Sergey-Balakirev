/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191289/step/9?unit=1204277}
 *
 * Via int 'global_ptr' pointer dereference interger value 10 if 'global_ptr' is
 * refers to the allocated memory area.
 *
 * 'global_ptr' pointer is declared and exis, but not visible for now.
 *
 */

#include <stdio.h>

int main(void) {
  if (global_ptr != NULL) {
    *global_ptr = 10;
  }
  return 0;
}
