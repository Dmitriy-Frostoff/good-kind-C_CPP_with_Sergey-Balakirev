/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191306/step/6?unit=1204294}
 *
 */

#include <stdio.h>

#define MARKS_SIZE 20

int get_numbers_to_arr(int arr[], size_t arr_size);
int is_even(int num);
int sum_ar(const int arr[], size_t len_arr, int (*check_callback)(const int));

int main(void) {
  int marks[MARKS_SIZE] = {0};
  size_t marks_size = sizeof(marks) / sizeof(*marks);

  // fill the @link{marks} array
  if (get_numbers_to_arr(marks, marks_size) != 0) {
    return 1;
  }

  // count sum of even numbers and print it to the console
  printf("%d\n", sum_ar(marks, marks_size, is_even));

  return 0;
}

/**
 *  @brief Get the numbers from the input to @linl{arr}
 *
 *  @note !Impure function! Mutates the @link{arr}
 *
 *  @param {int[]} arr - array of integers
 *  @param {size_t} arr_size - size of @link{arr}
 *
 *  @return {int} - 0, everything is OK
 *
 *  @example
 *    int arr[20] = {0}
 *      get_numbers_to_arr(arr, 20) =>
 *      INPUT:
 *      1 2 3 4 5 => 0
 *      arr{1, 2, 3, 4, 5}
 */
int get_numbers_to_arr(int arr[], size_t arr_size) {
  int x = -1;
  int nums_count = 0;

  while (scanf("%d", &x) == 1) {
    if (nums_count == arr_size) {
      break;
    }

    arr[nums_count] = x;
    nums_count += 1;
  }

  return 0;
}

/**
 *  @brief Check that number is even or odd
 *
 *  @param {const int} num - number for check
 *
 *  @return {int} - 1, @link{num} is even
 *  @return {int} - 0, @link{num} is odd
 *
 *  @example
 *    is_even(2) => 1
 *    is_even(3) => 0
 *    is_even(0) => 1
 *    is_even(-42) => 1
 *    is_even(-17) => 1
 */
int is_even(int num) {
  return num % 2 == 0 ? 1 : 0;
}

/**
 *  @brief Sum the even numbers from the @link{arr}
 *
 *  @param {int[]} arr - array of integers
 *  @param {size_t} len_arr - array length
 *  @param {int (*)(const int num)} check_callback - callback for checking the
 *   @link{arr} num
 *
 *  @return {int} - sum of the even numbers
 *
 *  @example
 *    const arr[20] = {1, 2, 3, 4, 5}
 *    @see{is_even}
 *      sum_ar(arr, 20, is_even) => 6
 *        2 + 4 => 6
 */
int sum_ar(const int arr[], size_t len_arr, int (*check_callback)(const int)) {
  int sum = 0;

  for (size_t i = 0; i < len_arr; i += 1) {
    if (check_callback(arr[i]) == 1) {
      sum += arr[i];
    }
  }

  return sum;
}
