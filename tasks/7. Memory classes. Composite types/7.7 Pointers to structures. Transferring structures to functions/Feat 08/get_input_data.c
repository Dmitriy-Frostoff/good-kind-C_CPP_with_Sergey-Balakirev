#include "./utils.h"

/**
 *  @brief Get the data from the INPUT: and save it to the @link{arr}
 *
 *  @note ! Impure function !
 *  - mutates the outer @link{arr}
 *  - implicit dependency on @link{POINT} type
 *
 *  @param {POINT []} arr - array to fill with points
 *  @param {size_t} arr_capacity - size of @link{arr}
 *
 *  @return {size_t} - quantity of read and saved points
 *  @return {0} - in the case below
 *  @throw if not incomplete pair of coordinates were produced
 *
 *  @example
 *    POINT arr[4] = {};
 *    size_t arr_size = 4;
 *
 *    get_input_data(arr, arr_size) =>
 *    INPUT:
 *    5 7 21 14 => 2
 *    arr[0].x = 5
 *    arr[0].y = 7
 *    arr[1].x = 21
 *    arr[1].y = 14
 *
 *    get_input_data(arr, arr_size) =>
 *    INPUT:
 *    '\0' => 0
 *    arr[0].x = 0
 *    arr[0].y = 0
 *    arr[0].x = 0
 *    arr[0].y = 0
 *
 */
size_t get_input_data(POINT arr[], size_t arr_capacity) {
  int temp_x = 0;
  int temp_y = 0;

  size_t points_count = 0;

  while (points_count < arr_capacity) {
    // quantity of read nums
    int input_log = scanf("%d %d", &temp_x, &temp_y);

    if (input_log != 2 || input_log == EOF) {
      break;
    }

    // assigning value to the fields of the point
    arr[points_count].x = temp_x;
    arr[points_count].y = temp_y;

    points_count += 1;
  }

  return points_count;
}
