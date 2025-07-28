#include "./utils.h"

/**
 *  @brief Get the input data from the INPUT: and assign it to the variables
 *
 *  @note ! Impure function !
 *  - mutates the outer @link{obj_1} and @link{obj_2}
 *  - implicit dependency on @link{POINT} type
 *
 *  @param {POINT *} obj_1 - address of the structure to assign read value (to
 *    the correspondent fields)
 *  @param {POINT *} obj_2 - address of the structure to assign read value (to
 *    the correspondent fields)
 *
 *  @return {0} - everything OK
 *  @return {-1} - problems via data reading from the INPUT:
 *  @throw if not 4 space separated integers were read or some problems
 *    occured
 *
 *  @example
 *    POINT obj_1 = {};
 *    POINT obj_2 = {};
 *
 *    get_input_data(&obj_1, &obj_2) =>
 *    INPUT:
 *    8 11 18 44 => 0
 *    obj_1.x = 8
 *    obj_1.y = 11
 *    obj_1.x = 18
 *    obj_1.y = 44
 *
 *    get_input_data(&obj_1, &obj_2) =>
 *    INPUT:
 *    '\0' => -1
 *    obj_1.x = 0
 *    obj_1.y = 0
 *    obj_1.x = 0
 *    obj_1.y = 0
 *
 */
int get_input_data(POINT *obj_1, POINT *obj_2) {
  int temp_x_0 = 0;
  int temp_y_0 = 0;
  int temp_x_1 = 0;
  int temp_y_1 = 0;

  if (scanf("%d %d %d %d", &temp_x_0, &temp_y_0, &temp_x_1, &temp_y_1) != 4) {
    puts("Error(get_input_data function): expected four space separated "
         "integers");
    return -1;
  }

  // assigning value to the fields of @link{obj_1) and @link{obj_2)
  obj_1->x = temp_x_0;
  obj_1->y = temp_y_0;
  obj_2->x = temp_x_1;
  obj_2->y = temp_y_1;

  return 0;
}
