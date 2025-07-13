/**
 *  The task description is at
 *  @link{https://stepik.org/lesson/1191309/step/10?unit=1204297}
 *
 */

#include "./config.h"
#include "./utils.h"

int main(void) {
  char str[STR_SIZE] = {0};
  size_t str_len = sizeof(str);
  double doubles_arr[ARR_SIZE] = {0};
  size_t doubles_arr_size = sizeof(doubles_arr) / sizeof(*doubles_arr);
  int read_nums_quantity = 0;

  // get the string from the INPUT:
  get_string_data(str, str_len);

  // remove last '\n' from the @link{str}
  remove_last_n(str);

  // fill @link{doubles_arr} with real numbers got from the @link{str}
  read_nums_quantity = get_data_csv(doubles_arr, doubles_arr_size, str);

  // Error ? => return non 0 exitcode
  if (read_nums_quantity == -1) {
    return 1;
  }

  // print the @link{doubles_arr} nums to the console
  print_arr_nums(doubles_arr, read_nums_quantity);

  return 0;
}
