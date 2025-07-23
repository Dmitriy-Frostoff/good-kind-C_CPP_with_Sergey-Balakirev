#include "./utils.h"

/**
 *  @brief Get the input data and assign it to the outer variables
 *
 *  @note ! Impure function! Mutates outer @link{type}, @link{width},
 *    @link{height} !
 *  @note ! Depends on global @link{enum calc_types} !
 *
 *  @param {enum calc_types *} type - enum calc_types {
 *    _perimetr = 1, _square = 2
 *  }
 *  @param {double *} width - width of the rectangle
 *  @param {double *} height - height  of the rectangle
 *
 *  @return {0} - everything OK
 *  @return {1} - not three numbers were got
 *  @throw if not three numbers were produced
 *
 *  @example
 *    enum calc_types type;
 *    double width;
 *    double height
 *    get_input_data(&type, &width, &height) =>
 *    INPUT:
 *    1 3.5 7.8 => 0
 *    type{1}
 *    width{3.5}
 *    height{7.8}
 *
 *    get_input_data(&type, &width, &height) =>
 *    INPUT:
 *    1 => 1
 *    OUTPUT:
 *    "Error: get_input_data() function. Expected three numbers: int type,
 *      double width, double height  at the INPUT:"
 *
 */
int get_input_data(enum calc_types *type, double *width, double *height) {
  if (scanf("%d %lf %lf", type, width, height) != 3) {
    puts("Error: get_input_data() function. Expected three numbers: int type, "
         "double width, double height at the INPUT:");
    return 1;
  }

  return 0;
}
