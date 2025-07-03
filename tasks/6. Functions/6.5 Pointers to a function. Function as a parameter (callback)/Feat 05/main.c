/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191306/step/7?unit=1204294}
 *
 */

#include <stddef.h>
#include <stdio.h>

#define FUNCS_SIZE 4
#define MARKS_SIZE 20

int get_criteria_for_sum(void);
int get_numbers_to_arr(int arr[], size_t arr_size);
int count_sum_via_chosen_func(
    int ITEM,
    int (*sum_ar_callback)(const int arr[], size_t len_arr,
                           int (*check_callback)(const int)),
    const int arr[], size_t len_arr, int (*funcs[])(int), size_t sizeof_funcs);
int is_odd(int num);
int is_positive(int num);
int is_negative(int num);
int deflt(int num);
int sum_ar(const int arr[], size_t len_arr, int (*check_callback)(const int));

int main(void) {
  int (*funcs[FUNCS_SIZE])(int) = {is_odd, is_positive, is_negative, deflt};
  size_t funcs_size = sizeof(funcs) / sizeof(*funcs);
  int marks[MARKS_SIZE] = {0};
  size_t marks_size = sizeof(marks) / sizeof(*marks);
  int sum = 0;

  // get the criteria for sum functions
  int item = get_criteria_for_sum();

  // fill the @link{marks} array
  if (get_numbers_to_arr(marks, marks_size) != 0) {
    return 1;
  }

  // count the sum of numbers in @link{mark} via function
  sum = count_sum_via_chosen_func(item, sum_ar, marks, marks_size, funcs,
                                  funcs_size);

  // print it to the console
  printf("%d\n", sum);

  return 0;
}

/**
 *  @brief Get the criteria from the input for summing
 *  @note !Impure function! Uses the INPUT
 *
 *
 *  @param {int} criteria - number for chosing
 *
 *  @return {int} - the @linl{criteria} value
 *  @throw if empty data was produced with exit code -1
 *
 *  @example
 *    get_criteria_for_sum() =>
 *    INPUT:
 *    1 => 1
 */
int get_criteria_for_sum(void) {
  int item = 0;
  if (scanf("%d", &item) != 1) {
    puts("Error: incorrect input");
    return -1;
  };

  return item;
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
 *  @brief Wrapper over the logic of counting sum via @link{ITEM} (=> chosen
 *    function)
 *
 *  @note Currently defined options for user input @link{ITEM}:
 *    1 => calculate sum of odd numbers
 *    2 => calculate sum of non-negative numbers
 *    3 => calculate sum of negative numbers
 *    4 => just calculate sum of all integers of @link{arr}
 *
 *  @param {int} ITEM - user chosen integer (1...4, ITEM > 0)
 *  @param {int (*)(const int arr[], size_t len_arr,
 *                          int (*check_callback)(const int))} sum_ar_callback -
 *    callback for calculating sum of @link{arr} integers via the criteria. e.g.
 *    @see{sum_ar}
 *  @param {const int[]} arr - array of marks
 *  @param {type} len_arr - length of @link{arr}
 *  @param {int (*[])(int)} funcs - array of pointers to the callbacks for
 *    checking @link{arr} nums to calculate sum of
 *  @param {size_t} sizeof_funcs - length of @link{funcs}
 *
 *  @return {int} - counted sum of @link{arr} integers
 *  @throw if @link{item} is < 1. Returns exit code -1
 *
 *  @example
 *    const int ITEM = 1;
 *    sum_ar - @see{sum_ar} for details;
 *    const arr[20] = {5, 4, 3, 5, 6, 78, 89, 56, , 43, , 456, 45, 645, 45, 44,
 *      3, 1, 4};
 *    len_arr = 20;
 *    int (*funcs[4])(int) = {is_odd, is_positive, is_negative, deflt};
 *      @see{is_odd}, @see{is_positive}, @see{is_negative}, @see{deflt} for
 *      details
 *    size_t sizeof_funcs = 4;
 *      count_sum_via_chosen_func(ITEM, sum_ar, len_arr, funcs, sizeof_funcs) =>
 *       884
 *       got the sum of "odd" numbers of the "arr" via "is_odd" checking func
 */
int count_sum_via_chosen_func(
    const int ITEM,
    int (*sum_ar_callback)(const int arr[], size_t len_arr,
                           int (*check_callback)(const int)),
    const int arr[], size_t len_arr, int (*funcs[])(int), size_t sizeof_funcs) {
  int sum = 0;

  if (ITEM - 1 < 0) {
    puts("Error: expected ITEM to be > 0");
    return -1;
  }

  switch (ITEM) {
  case 1:
    sum = sum_ar_callback(arr, len_arr, funcs[ITEM - 1]);
    break;
  case 2:
    sum = sum_ar_callback(arr, len_arr, funcs[ITEM - 1]);
    break;
  case 3:
    sum = sum_ar_callback(arr, len_arr, funcs[ITEM - 1]);
    break;
  default:
    sum = sum_ar_callback(arr, len_arr, funcs[sizeof_funcs - 1]);
    break;
  }

  return sum;
}

/**
 *  @brief Check that number is odd
 *
 *  @param {const int} num - number for check
 *
 *  @return {int} - 1, @link{num} is odd
 *  @return {int} - 0, @link{num} is even
 *
 *  @example
 *    is_odd(2) => 0
 *    is_odd(3) => 1
 *    is_odd(0) => 0
 *    is_odd(-42) => 0
 *    is_odd(-17) => 1
 */
int is_odd(int num) {
  if (num >= 0) {
    return num % 2 != 0 ? 1 : 0;
  }

  return num % 2 != -0 ? 1 : 0;
}

/**
 *  @brief Check that number is non-negative (>=0)
 *
 *  @param {const int} num - number for check
 *
 *  @return {int} - 1, @link{num} is non - negative
 *  @return {int} - 0, @link{num} is negative
 *
 *  @example
 *    is_positive(2) => 1
 *    is_positive(0) => 1
 *    is_positive(-42) => 0
 */
int is_positive(int num) {
  return num >= 0 ? 1 : 0;
}

/**
 *  @brief Check that number is negative
 *
 *  @param {const int} num - number for check
 *
 *  @return {int} - 1, @link{num} is negative
 *  @return {int} - 0, @link{num} is  non - negative
 *
 *  @example
 *    is_negative(2) => 0
 *    is_negative(0) => 0
 *    is_negative(-42) => 1
 */
int is_negative(int num) {
  return num < 0 ? 1 : 0;
}

/**
 *  @brief Just always returns 1
 *
 *  @param {const int} num - number for check (is not used)
 *
 *  @return {int} - 1, always returns 1
 *
 *  @example
 *    deflt(2) => 1
 *    deflt(0) => 1
 *    deflt(-42) => 1
 */
int deflt(int num) {
  return 1;
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
