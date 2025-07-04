/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191308/step/5?unit=1204296}
 *
 */

#include "./config.h"
#include "./utils.h"

int main(void) {
  int max_rec;
  int arr[MAX_LENGTH];
  size_t arr_size = sizeof(arr) / sizeof(*arr);

  // get from the input max range value
  max_rec = get_max_range_value();

  // fill the @link{arr} with integers [ 1 : @link{max_rec} ]
  size_t cnt = range_to_ar(arr, MAX_LENGTH, 1, max_rec, 0);

  // print to the terminal first @link{cnt} nums
  print_arr_nums(arr, arr_size, cnt);

  return 0;
}
