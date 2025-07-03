/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191303/step/7?unit=1204291}
 *
 */

#include <math.h>
#include <stdio.h>

#define MAX_SAFE_INTEGER 2147483647

/**
 *  @brief Get the sum2 of two integers
 *
 *  Integers and their sum are in range [-2 147 483 648; 2 147 483 647]
 *
 *  @note
 *    (!) Do not use with numbers like |MAX_SAFE_INTEGER / 2 + 1|
 *    because one'll hae got incorrect result => NAN + num => 1 + num
 *
 *  @param {int} num_1 - integer in range [-2 147 483 648; 2 147 483 647]
 *  @param {int} num_2 - integer in range [-2 147 483 648; 2 147 483 647]
 *
 *  @return {int | NAN} - sum of integers or NAN
 *  @throw "the |sum of integers| > 2 147 483 647"
 *
 *  @example
 *    get_sum2(0, 1) => 1
 *    get_sum2(-10, 5) => -5
 *    get_sum2(-10, 2147483648) => "the |sum of integers| > 2 147 483 647"
 *    get_sum2(-2147483648, -10) => "the |sum of integers| > 2 147 483 647"
 *    get_sum2(1073741825, 1073741824) =>
 *     "the |sum of integers| > 2 147 483 647"
 *    get_sum2(NAN, 1073741824) => ???(!) 1073741825
 */
int get_sum2(int num_1, int num_2) {
  // sum out of range for int ? => message and return
  if ((num_1 > 0 && num_2 > 0 && (num_1 + num_2) <= 0) ||
      (num_1 < 0 && num_2 < 0 && (num_1 + num_2) >= 0)) {
    puts("the |sum of integers| > 2 147 483 647");
    return NAN;
  }

  int res = num_1 + num_2;
  return res;
}

int main(void) {
  int num_1 = 0;
  int num_2 = 0;
  int num_3 = 0;

  // 'scanf' with "%d" sets 'input num' in range [-2 147 483 648; 2 147 483 647]
  if (scanf("%d %d %d", &num_1, &num_2, &num_3) != 3) {
    puts("expected three integers each in range [-2 147 483 648; 2 147 483 "
         "647]");
    return 0;
  }

  printf("%d\n", get_sum2(get_sum2(num_1, num_2), num_3));
  return 0;
}
