/**
 *  The task description is at
 *  @link{https://stepik.org/lesson/1191318/step/9?unit=1204306}
 *
 */

#include "./config.h"
#include "./utils.h"

int main(void) {
  DATA res_1 = {};
  DATA res_2 = {};

  // count sums due to the chosen type of @link{TYPE_PARAM}
  res_1 = sum_ar((DATA[]){{.data_i = 1},
                          {.data_i = 2},
                          {.data_i = 3},
                          {.data_i = 4},
                          {.data_i = 5}},
                 SIZE_OF_ARR, param_int);
  res_2 = sum_ar((DATA[]){{.data_d = 1.1},
                          {.data_d = 2.2},
                          {.data_d = 3.3},
                          {.data_d = 4.4},
                          {.data_d = 5.5}},
                 SIZE_OF_ARR, param_double);

  return 0;
}
