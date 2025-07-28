/**
 *  The task description is at
 *  @link{https://stepik.org/lesson/1191316/step/10?unit=1204304}
 *
 */

#include "./config.h"
#include "./utils.h"

int main(void) {
  POINT pts_arr[ARR_SIZE] = {};
  size_t pts_arr_capacity = sizeof(pts_arr) / sizeof(*pts_arr);
  size_t read_pts_quantity = 0;

  DATA mean_pts_coord_obj = {};

  // get coordinates for points
  read_pts_quantity = get_input_data(pts_arr, pts_arr_capacity);

  if (read_pts_quantity == 0) {
    return 1;
  }

  // get pts means structure
  mean_pts_coord_obj = get_means(pts_arr, read_pts_quantity);

  // print the @link{counted_square}
  printf("%.2f %.2f\n", mean_pts_coord_obj.mean_x, mean_pts_coord_obj.mean_y);

  return 0;
}
