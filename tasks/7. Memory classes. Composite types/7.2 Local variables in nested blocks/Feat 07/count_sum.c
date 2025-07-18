#include "./utils.h"

/**
 *  @brief Count sum via formula Sum(i[0; N], j[0; M])
 *
 *  Count sum via formula Sum(i[0; N] step +1, j[0; M] step +1),
 *  if i + j >= 20 return current sum.
 *  Uses two nested for cycles (O(N) = n ** 2)
 *
 *  @note ! Impure function! Uses macros @link{MAX_N_M_SUM} under the hood !
 *
 *  @param {int} n - max range value for the first param
 *  @param {int} m - max range value for the second param
 *
 *  @return {int} - counted sum
 *
 *  @example
 *    count_sum(7, 8) => 540
 *    count_sum(10, 4) => 385
 *    count_sum(3, 5) => 96
 *    count_sum(15, 30) => 190
 *
 */
int count_sum(int n, int m) {
  int sum = 0;

  for (int i = 0; i <= n; i += 1) {
    for (int j = 0; j <= m; j += 1) {
      if (i + j == MAX_N_M_SUM) {
        return sum;
      }

      sum += i + j;
    }
  }

  return sum;
}
