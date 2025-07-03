/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191302/step/4?unit=1204290}
 *
 */

#include <stdio.h>

/**
 *  Returns string "It's my first function"
 *
 *  @param {void}
 *  @return {char[]} "It's my first function\n\0"
 *
 *  @example
 *   show_info() => "It's my first function"
 */
void show_info(void) {
  puts("It's my first function");
}

int main(void) {
  show_info();

  return 0;
}
