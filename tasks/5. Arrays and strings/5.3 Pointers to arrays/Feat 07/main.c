/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191293/step/9?unit=1204281}
 *
 */

#include <stdio.h>

int main(void) {
  double arr_of_real_nums[20] = {0};
  double sum = 0;
  double avg_value = 0;
  // *arr_of_real_nums == arr_of_real_nums[0]
  double *ptr_arr_of_real_nums = &*arr_of_real_nums;
  unsigned char quantity_of_input_values = 0;

  while (scanf("%lf ", ptr_arr_of_real_nums) != EOF) {
    ptr_arr_of_real_nums += 1;
    quantity_of_input_values += 1;
  }

  // reset pointer
  ptr_arr_of_real_nums = &*arr_of_real_nums;

  for (unsigned char i = 0; i < quantity_of_input_values; i += 1) {
    sum += arr_of_real_nums[i];
  }

  avg_value = sum / quantity_of_input_values;

  printf("%.2f\n", avg_value);

  return 0;
}
