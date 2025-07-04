/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191306/step/7?unit=1204294}
 *
 */

#include "./config.h"
#include "./utils.h"

int main(void) {
  int (*funcs[FUNCS_SIZE])(int) = {is_odd, is_positive, is_negative, deflt};
  size_t funcs_size = sizeof(funcs) / sizeof(*funcs);
  int marks[MARKS_SIZE] = {0};
  size_t marks_size = sizeof(marks) / sizeof(*marks);
  int sum = 0;

  // get the criteria for sum functions
  int item = get_criteria_for_sum();

  // fill the @link{marks} array
  if (get_numbers_to_arr(marks, marks_size) != 0) {
    return 1;
  }

  // count the sum of numbers in @link{mark} via function
  sum = count_sum_via_chosen_func(item, sum_ar, marks, marks_size, funcs,
                                  funcs_size);

  // print it to the console
  printf("%d\n", sum);

  return 0;
}
