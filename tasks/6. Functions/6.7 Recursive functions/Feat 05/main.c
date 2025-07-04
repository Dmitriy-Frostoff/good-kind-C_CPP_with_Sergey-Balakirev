/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191308/step/7?unit=1204296}
 *
 */

#include "./config.h"
#include "./utils.h"

int main(void) {
  short ar_1[] = {-4, 2, 3, 7, 0};
  short ar_2[] = {11, 6, 10, 8, 13, 98, -5, 0};
  short ar_3[] = {-47, 0};
  short ar_4[] = {8, 11, 56, -3, -2, 0};

  short *table[] = {ar_1, ar_4, ar_3, ar_2};
  size_t table_row_length = sizeof(table) / sizeof(*table);

  short flat[MAX_LENGTH] = {0};
  size_t flat_length = sizeof(flat) / sizeof(*flat);

  size_t cnt = to_flat(flat, MAX_LENGTH, table, table_row_length, 0, 0, 0);

  // print the nums of @link{flat} array
  print_array_values(flat, flat_length, cnt);

  return 0;
}
