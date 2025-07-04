#include "./utils.h"

/**
 *  @brief count sum (called "y") via formula (1 / N) * Sum_1_to_N(of random xi)
 *  @note N is predifined as 100
 *
 *  Count sum of random xi (in range [a; b]) via formula above
 *    ("i" is in range [1; N])
 *
 *  @param {int} a - min range value
 *  @param {int} b - max range value
 *
 *  @return {double} - counted sum of random nums
 *
 *  @example
 *    norm(-2, 10) => 3.680000
 */
double norm(int a, int b) {
  const int N = 100;
  double sum_y = 0.;

  // create seed for random nums
  srand(time(NULL));

  // rand() % (b - a + 1) + a => get random num in range [a; b]
  for (int i = 1; i <= N; i += 1) {
    sum_y += (1 / (double)(N)) * (rand() % (b - a + 1) + a);
  }

  return sum_y;
}
