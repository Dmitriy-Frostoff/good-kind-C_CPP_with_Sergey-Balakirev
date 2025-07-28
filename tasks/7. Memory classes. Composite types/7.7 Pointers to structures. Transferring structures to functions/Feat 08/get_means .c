#include "./utils.h"

/**
 *  @brief Fill the structure of @type{DATA} with means of coordinates x (field
 *  mean_x) and with means of coordinates x (field mean_y) of array of points
 *  and return that strucure.
 *
 *  @note ! Impure fucntion !
 *  - implicit dependency on outer {DATA} type
 *  - implicit dependency on outer {POINT} type
 *  -
 *
 *  @param {const POINT []} arr - array of points
 *  @param {size_t} arr_size - qunatity of points to use (possibly not entire
 *    @link{arr} size)
 *
 *  @return {DATA} - filled with counted means structure
 *  @throw if quantity of 'x' and 'y' coordinates is not equal
 *
 *  @example
 *    POINT arr[] = {pt_0{x = 5; y = 7;}, pt_1{x = 21; y = 14;}};
 *    size_t arr_size = 2;
 *
 *    get_means(arr[], arr_size) =>
 *      DATA{mean_x = 13.00; mean_y = 10.50;}
 *
 */
DATA get_means(const POINT arr[], size_t arr_size) {
  double sum_x = 0.0;
  int count_x = 0;
  double sum_y = 0.0;
  int count_y = 0;
  double mean_x = 0.0;
  double mean_y = 0.0;

  DATA mean_data_obj = {};

  // count sums
  for (size_t i = 0; i < arr_size; i += 1) {
    sum_x += arr[i].x;
    count_x += 1;
    sum_y += arr[i].y;
    count_y += 1;
  }

  if (count_x != count_y) {
    puts("Error(get_means() function): missed coordinates found");
    return mean_data_obj;
  }

  // count means
  mean_x = sum_x / count_x;
  mean_y = sum_y / count_y;

  // assigning counted means to the result structure of @type{DATA}
  mean_data_obj.mean_x = mean_x;
  mean_data_obj.mean_y = mean_y;

  return mean_data_obj;
}
