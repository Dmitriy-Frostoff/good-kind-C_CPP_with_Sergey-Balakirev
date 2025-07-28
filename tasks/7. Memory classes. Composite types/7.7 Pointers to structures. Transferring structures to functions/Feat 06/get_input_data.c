#include "./utils.h"

/**
 *  @brief Get the input data from the INPUT: and assign it to the variables
 *
 *  @note ! Impure function !
 *  - mutates the outer @link{obj_1} and @link{obj_2}
 *  - implicit dependency on @link{COMPLEX} type
 *
 *  @param {COMPLEX *} obj_1 - address of the structure to assign read value (to
 *    the correspondent fields)
 *  @param {COMPLEX *} obj_2 - address of the structure to assign read value (to
 *    the correspondent fields)
 *
 *  @return {0} - everything OK
 *  @return {-1} - problems via data reading from the INPUT:
 *  @throw if not 4 comma separated real numbers were read or some problems
 *    occured
 *
 *  @example
 *    COMPLEX obj_1 = {};
 *    COMPLEX obj_2 = {};
 *
 *    get_input_data(&obj_1, &obj_2) =>
 *    INPUT:
 *    0.1, 0.2, -0.5, 4.6 => 0
 *    obj_1.re = 0.1
 *    obj_1.im = 0.2
 *    obj_1.re = -0.5
 *    obj_1.im = 4.6
 *
 *    get_input_data(&obj_1, &obj_2) =>
 *    INPUT:
 *    '\0' => -1
 *    obj_1.re = 0.0
 *    obj_1.im = 0.0
 *    obj_1.re = 0.0
 *    obj_1.im = 0.0
 *
 */
int get_input_data(COMPLEX *obj_1, COMPLEX *obj_2) {
  double temp_real_1 = 0.0;
  double temp_imagi_1 = 0.0;
  double temp_real_2 = 0.0;
  double temp_imagi_2 = 0.0;

  if (scanf("%lf, %lf, %lf, %lf", &temp_real_1, &temp_imagi_1, &temp_real_2,
            &temp_imagi_2) != 4) {
    puts("Error(get_input_data function): expected four comma separated real "
         "numbers");
    return -1;
  }

  // assigning value to the fields of @link{obj_1) and @link{obj_2)
  obj_1->re = temp_real_1;
  obj_1->im = temp_imagi_1;
  obj_2->re = temp_real_2;
  obj_2->im = temp_imagi_2;

  return 0;
}
