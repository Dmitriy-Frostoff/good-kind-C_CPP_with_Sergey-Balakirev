#include "./utils.h"

/**
 *  @brief Get the variables values from the INPUT:
 *
 *  @note ! Impure function! Mutates the outer @link{start}, @link{stop},
 *  @link{step} variables !
 *
 *  @param {int *} start - pointer to the start variable
 *  @param {int *} stop - pointer to the stop variable
 *  @param {int *} step - pointer to the step variable
 *
 *  @return {0} - everything OK
 *  @return {1} - incorrect INPUT: was produced
 *
 *  @example
 *    int start;
 *    int stop;
 *    int step;
 *
 *    get_variables_values(&start, &stop, &step) =>
 *      INPUT:
 *      5 11 2 => 0
 *      start{5}, stop{11}, step{2}
 *
 *    -//-
 *    get_variables_values(&start, &stop, &step) =>
 *      INPUT:
 *      5 => 1
 *      "Error: expected three space separated integers like this 'start stop
 *        step'"
 *
 */
int get_variables_values(int *start, int *stop, int *step) {
  if (scanf("%d %d %d", start, stop, step) != 3) {
    puts("Error: expected three space separated integers like this 'start stop "
         "step'");
    return 1;
  }

  return 0;
}
