/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191310/step/8?unit=1204298}
 *
 */

#include "./config.h"
#include "./utils.h"

int main(void) {
  int marks[ARR_SIZE] = {0};
  size_t marks_size = sizeof(marks) / sizeof(*marks);
  size_t written_nums_count = 0;
  double mean_value;

  // get @link{marks_size} integers into the @link{marks} array
  written_nums_count = get_ints_to_arr(marks, marks_size);

  if (!written_nums_count) {
    puts("Error: empty input data");
    return 1;
  }

  // get mean of the @link{marks} array
  mean_value = mean_ar(marks, marks_size, is_num_in_range_1_5);

  printf("%.1f", mean_value);

  return 0;
}
