/**
 *  The task description is at
 *  @link{https://stepik.org/lesson/1191315/step/10?unit=1204303}
 *
 */

#include "./config.h"
#include "./utils.h"

int main(void) {
  struct tag_point_3d points[total_points] = {0};
  size_t points_size = sizeof(points) / sizeof(*points);
  size_t total = 0;

  // get input data
  // TODO! Extract to the standalone function
  // size_t get_data(struct tag_point_3d *points, points_size)

  while (total < points_size) {
    int temp_x = 0;
    int temp_y = 0;
    int temp_z = 0;

    // get x, y, z coordinates
    if (get_input_data(&temp_x, &temp_y, &temp_z) == 0) {
      points[total].x = temp_x;
      points[total].y = temp_y;
      points[total].z = temp_z;
      total += 1;
      continue;
    }

    break;
  }

  // print last written point coordinates
  printf("%d %d %d", points[total - 1].x, points[total - 1].y,
         points[total - 1].z);

  /*
   * макроопределение для тестирования
   * (не убирать и должно идти непосредственно перед return 0)
   */
  __ASSERT_TESTS__
  return 0;
}
