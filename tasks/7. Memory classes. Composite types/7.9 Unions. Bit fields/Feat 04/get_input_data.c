#include "./utils.h"

/**
 *  @brief Get the input data from the INPUT: and assign it to the structure
 *
 *  Input 1 (for two integers coordinates) or 2 (for two real numbers
 *  coordinates) than input two space separated numbers due to descriptions
 *  above (for 1 or 2)
 *
 *  @note ! Impure function !
 *  - mutates the outer @link{obj}
 *  - implicit dependency on @link{POINT2} type
 *  - implicit dependency on @link{TYPE_COORD} type
 *
 *  @param {POINT2 *} obj - address of the structure to assign read value (to
 *    the correspondent fields)
 *
 *  @return {0} - everything OK
 *  @return {-1} - problems via data reading from the INPUT:
 *  @throw if got type is not 1 or 2 (first INPUT: param)
 *  @throw if first INPUT: is 1 and got not 2 space separated integers
 *  @throw if first INPUT: is 2 and got not 2 space separated real numbers
 *
 *  @example
 *    COMPLEX obj = {};
 *
 *    get_input_data(&obj) =>
 *    INPUT:
 *    1
 *    INPUT:
 *    10 20 => 0
 *    =>
 *    obj.type = 1;
 *    obj.x.coord_i = 10;
 *    obj.y.coord_i = 20;
 *
 *    get_input_data(&obj) =>
 *    INPUT:
 *    2
 *    INPUT:
 *    0.5 -2.5 => 0
 *    =>
 *    obj.type = 2;
 *    obj.x.coord_d = 0.5;
 *    obj.y.coord_d = -2.5;
 *
 *    get_input_data(&obj) =>
 *    INPUT:
 *    0
 *    OUTPUT:
 *    Error(get_input_data() function at 64): expected 1 or 2 as INPUT:
 *
 *    get_input_data(&obj) =>
 *    INPUT:
 *    1
 *    INPUT:
 *    EOF
 *    OUTPUT:
 *    Error(get_input_data() function at 82): expected two space separated
 *      integers
 *
 *    get_input_data(&obj) =>
 *    INPUT:
 *    2
 *    INPUT:
 *    EOF
 *    OUTPUT:
 *    Error(get_input_data() function at 101): expected two space separated real
 *      numbers (type double)
 *
 */
int get_input_data(POINT2 *obj) {
  TYPE_COORD got_type = 0;

  int got_int_x_coord = 0;
  int got_int_y_coord = 0;

  double got_double_x_coord = 0.0;
  double got_double_y_coord = 0.0;

  // get @link{got_type} from the INPUT:
  if (scanf("%d", &got_type) != 1 || got_type < 1 || got_type > 2) {
    fprintf(stderr, "Error(%s() function at %d): expected 1 or 2 as INPUT:\n",
            __func__, __LINE__);
    return -1;
  }

  switch (got_type) {
  case coord_int:
    if (scanf("%d %d", &got_int_x_coord, &got_int_y_coord) != 2) {
      fprintf(
          stderr,
          "Error(%s() function at %d): expected two space separated integers\n",
          __func__, __LINE__);
      return -1;
    }
    break;
  case coord_double:
    if (scanf("%lf %lf", &got_double_x_coord, &got_double_y_coord) != 2) {
      fprintf(stderr,
              "Error(%s() function at %d): expected two space separated real "
              "numbers (type double)\n",
              __func__, __LINE__);
      return -1;
    }
    break;
  default:
    fprintf(stderr, "Error(%s() function at %d): got type is not defined\n",
            __func__, __LINE__);
    return -1;
  }

  // assigning value to the fields of @link{obj)
  if (got_type == coord_int) {
    obj->type = got_type;
    obj->x.coord_i = got_int_x_coord;
    obj->y.coord_i = got_int_y_coord;
    return 0;
  }

  obj->type = got_type;
  obj->x.coord_d = got_double_x_coord;
  obj->y.coord_d = got_double_y_coord;
  return 0;
}
