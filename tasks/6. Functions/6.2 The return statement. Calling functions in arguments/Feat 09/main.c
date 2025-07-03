/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191303/step/11?unit=1204291}
 *
 */

#include <stdio.h>

/**
 *  @brief Get the arithmetic mean via formula for every num in the row
 *
 *  @param {double} qm_1 - previously counted arithmetic mean (first qm => 0)
 *  @param {int} m - quantity of read integers (first => 1)
 *  @param {int} x - current integer in the row
 *    in range [-2 147 483 648; 2 147 483 647]
 *
 *  @return {double} - counted arithmetic mean
 *
 *  @example
 *    @note 4 3 2 -10 => -0.25
 *    get_qm(0, 1, 4) => 4.000000
 *      m = 1, qm_1 = 0, x = 4
 *      ((1 - 1) / 1.0) * 0 + (1 / 1.0) * 4 => 4.000000
 *    get_qm(4, 2, 3) => 3.500000
 *      m = 2, qm_1 = qm prev = 4.000000, x = 3
 *      ((2 - 1) / 2.0) * 4.000000 + (1 / 2.0) * 3 => 3.500000
 *    get_qm(3.5, 3, 2) => 3.000000
 *    get_qm(3.0, 4, -10) => -0.250000
 */
double get_qm(double qm_1, int m, int x) {
  double qm = ((m - 1) / (double)m) * qm_1 + (1 / (double)m) * x;
  return qm;
}

/**
 *  @brief print (rounded to thousands) calculated iteratively arithmetic mean
 *    over the input numbers (space separated)
 *
 *  @return {int} - 0, everything is OK
 *
 *  @example
 *     4 3 2 -10 56 3 0 1 => 7.375
 */
int main(void) {
  int x;
  int m = 1;
  double qm = 0;
  double qm_1 = 0;

  while (scanf("%d", &x) == 1) {
    // count current arithmetic mean
    qm = get_qm(qm_1, m, x);

    // increase counter of numbers
    m += 1;

    // set previous arithmetic mean
    qm_1 = qm;
  }

  printf("%.3f\n", qm);

  return 0;
}
