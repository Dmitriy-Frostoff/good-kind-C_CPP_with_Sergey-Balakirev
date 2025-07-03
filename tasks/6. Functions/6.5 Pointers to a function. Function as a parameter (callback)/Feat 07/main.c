/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191306/step/9?unit=1204294}
 *
 */

#include <stddef.h>
#include <stdio.h>

int get_integers(int *num_1, int *num_2, int *num_3, int *num_4);
int sum_big2(int a, int b, int c, int d);

int main(void) {
  int num_1;
  int num_2;
  int num_3;
  int num_4;
  int sum = 0;

  // get 4 integers from the INPUT
  get_integers(&num_1, &num_2, &num_3, &num_4);

  // get the sum of two biggest integers
  sum = sum_big2(num_1, num_2, num_3, num_4);

  printf("%d\n", sum);

  return 0;
}

/**
 *  @brief Get four integers from the input
 *
 *  @note !Impure function! It mutates the originals values of params
 *
 *  @param {int *} num_1 - integer
 *  @param {int *} num_2 - integer
 *  @param {int *} num_3 - integer
 *  @param {int *} num_4 - integer
 *
 *  @return {int} - 0, everything OK
 *  @throw if empty data was produced and return exit code 1
 *
 *  @example
 *    int num_1, num_2, num_3, num_4;
 *      get_integers(&num_1, &num_2, &num_3, &num_4) =>
 *      INPUT:
 *      1 2 3 -4 => 0
 *      num_1 = 1; num_2 = 2; num_3 = 3; num_4 = -4;
 */
int get_integers(int *num_1, int *num_2, int *num_3, int *num_4) {
  if (scanf("%d %d %d %d", num_1, num_2, num_3, num_4) != 4) {
    puts("Error: expected 4 integers");
    return 1;
  }

  return 0;
}

/**
 *  @brief Get the sum of two the greatest of four integers
 *
 *  @param {int} a - number
 *  @param {int} b - number
 *  @param {int} c - number
 *  @param {int} d - number
 *
 *  @return {int} - sum of two the greatest numbers
 *
 *  @example
 *    sum_big2(0, 1, 2, 3, get_max_of_two_nums) => 5
 *    sum_big2(0, 1, 3, 3, get_max_of_two_nums) => 6
 */
int sum_big2(int a, int b, int c, int d) {
  int arr[4] = {a, b, c, d};
  size_t arr_length = sizeof(arr) / sizeof(*arr);

  // to choose the least value instead of NULL (C doesn't have NULL as empty
  //  value like NULL in TypeScript)
  int sum = a + b + c + d;
  int max_num = sum > 0 ? -sum : sum;
  int max_num_prev = max_num;

  for (size_t i = 0; i < arr_length; i += 1) {
    // if there're duplications in the @link{arr}
    if (arr[i] == max_num) {
      max_num_prev = max_num;
      continue;
    }

    // get the max num
    if (arr[i] > max_num) {
      max_num_prev = max_num;
      max_num = arr[i];
      continue;
    }

    // if current num is not the greatest, but greater than prev max
    if (arr[i] > max_num_prev && arr[i] < max_num) {
      max_num_prev = arr[i];
      continue;
    }
  }

  return max_num + max_num_prev;
}
