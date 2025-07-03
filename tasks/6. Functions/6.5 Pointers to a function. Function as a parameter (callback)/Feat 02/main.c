/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191306/step/4?unit=1204294}
 *
 */

#include <stdio.h>

int get_two_real_numbers(double *ptr_num_a, double *ptr_num_b);
double max_2(double a, double b);

int main(void) {
  double a;
  double b;

  double (*ptr_max_2)(double, double) = NULL;

  // set pointer to the max_2 function
  ptr_max_2 = max_2;

  // get two comma separated real numbers
  get_two_real_numbers(&a, &b);

  // get the max of two real numbers and print it to the terminal
  printf("%.1f\n", ptr_max_2(a, b));

  /*
   * макроопределение для тестирования
   * (не убирать и должно идти непосредственно перед return 0)
   */
  __ASSERT_TESTS__
  return 0;
}

/**
 *  @brief Get the two comma separated real numbers from the input
 *  @note !Impure function! Modifies given arguments via their pointers
 *
 *  @param {double *} num_a - pointer to the variable
 *  @param {double *} num_b - pointer to the variable
 *
 *  @return {int} - 0, everything is OK
 *  @throw if pointers are NULL or not two comma separated real numbers were
 *    produced and return exit code 1
 *
 *  @example
 *    double a, double b;
 *    get_two_real_numbers(&a, &b) =>
 *    INPUT:
 *    5.0 2.6
 *    => 0
 *    a = 5.0, b = 2.6
 */
int get_two_real_numbers(double *ptr_num_a, double *ptr_num_b) {
  if (ptr_num_a == NULL || ptr_num_b == NULL) {
    puts("Error: pointers are NULL");
    return 1;
  }

  if (scanf("%lf, %lf", ptr_num_a, ptr_num_b) != 2) {
    puts("Error: incorrect input. Expected two comma separated real numbers");
    return 1;
  }
  return 0;
}

/**
 *  @brief Get max of two real numbers
 *
 *  @param {double} a - real number
 *  @param {double} b - real number
 *
 *  @return {double} - max of given arguments
 *
 *  @example
 *    max_2(5.0, -2.0) => 5.0
 */
double max_2(double a, double b) {
  return (a > b) ? a : b;
}
