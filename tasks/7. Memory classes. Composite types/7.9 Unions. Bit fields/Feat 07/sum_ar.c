#include "./utils.h"

/**
 *  @brief Count number's sum of the given @link{arr} due to the
 *    @link{data_type} param
 *
 *  @note ! Impure function !
 *    - dependency on @type{DATA}
 *    - dependency on @type{TYPE_PARAM}
 *
 *  @param {DATA []} arr - array of elements to count sum (may be of @type{int}
 *    or of @type{double} )
 *  @param {size_t} arr_size - size of @link{arr}
 *  @param {TYPE_PARAM} data_type - type of given @link{arr} elements (i.e. int
 *    or double)
 *
 *  @return {DATA} - counted sum of elems of the set @link{data_type}
 *  @throw if @link{data_type} is not one of the predefined in the
 *    @link{TYPE_PARAM} types
 *
 *  @example
 *    DATA arr[] = {{.data_i = 7},
 *                  {.data_i = 8},
 *                  {.data_i = 15},
 *                  {.data_i = 23},
 *                  {.data_i = 42}};
 *    size_t arr_size = 5;
 *    sum_ar(arr, arr_size, param_int) => DATA {data_i = 95, data_d = 4.693623}
 *
 *    sum_ar((DATA[]){{.data_i = 1},
 *                    {.data_i = 2},
 *                    {.data_i = 3},
 *                    {.data_i = 4},
 *                    {.data_i = 5}},
 *      5, param_int) => DATA {data_i = 15, data_d = 7.41098}
 *
 *    sum_ar((DATA[]){{.data_d = 1.1},
 *                    {.data_d = 2.2},
 *                    {.data_d = 3.3},
 *                    {.data_d = 4.4},
 *                    {.data_d = 5.5}},
 *           5, param_int) => DATA {data_i = 0, data_d = 16.5}
 *
 */
DATA sum_ar(DATA arr[], size_t arr_size, TYPE_PARAM data_type) {
  DATA sum_int = {.data_i = 0};
  DATA sum_double = {.data_d = 0};

  // count correspondent sum due to the @link{data_type}
  switch (data_type) {
  case param_int:
    for (size_t i = 0; i < arr_size; i += 1) {
      sum_int.data_i += arr[i].data_i;
    }
    return sum_int;
  case param_double:
    for (size_t i = 0; i < arr_size; i += 1) {
      sum_double.data_d += arr[i].data_d;
    }
    return sum_double;
  default:
    fprintf(stderr, "Error(%s() at %d): %c is not defined in the TYPE_PARAM\n",
            __func__, __LINE__, data_type);
    return sum_int;
  }
}
