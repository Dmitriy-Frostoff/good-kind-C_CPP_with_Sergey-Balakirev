/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191306/step/6?unit=1204294}
 *
 */

#include "./config.h"
#include "./utils.h"

int main(void) {
  int marks[MARKS_SIZE] = {0};
  size_t marks_size = sizeof(marks) / sizeof(*marks);

  // fill the @link{marks} array
  if (get_numbers_to_arr(marks, marks_size) != 0) {
    return 1;
  }

  // count sum of even numbers and print it to the console
  printf("%d\n", sum_ar(marks, marks_size, is_even));

  return 0;
}
