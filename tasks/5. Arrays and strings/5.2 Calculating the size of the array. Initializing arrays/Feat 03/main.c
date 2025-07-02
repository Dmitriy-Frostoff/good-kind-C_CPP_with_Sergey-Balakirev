/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191292/step/5?unit=1204280}
 *
 * The array with name 'marks' that consist of elements with type short is
 * exist and dclared before main. Count 'marks' length (quantity of elements)
 * and sizeof 'marks' (entire, bytes). Print to the console (space separated)
 * counted 'marks' length 'marks' size.
 *
 */

#include <stdio.h>

int main(void) {
  size_t arr_length = sizeof(marks) / sizeof(*marks);
  size_t arr_size_bytes = sizeof(marks);

  printf("%zu %zu", arr_length, arr_size_bytes);

  return 0;
}
