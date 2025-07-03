/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191305/step/6?unit=1204293}
 *
 */

#include <stdio.h>
#include <string.h>

#define ARR_LENGTH 20
#define STR_LENGTH 100

int to_csv(char *str, const double arr[], int arr_length);

/**
 *  @brief get the real numbers(@type double) from the input (space separated)
 *    to the array and print to the console created string
 *
 *  @example
 *    0.01 5.43 0.785 11.9 => "csv: 0.01; 5.43; 0.79; 11.90"
 */
int main(void) {
  double arr_of_double[ARR_LENGTH] = {0};
  char str[STR_LENGTH] = {0};

  // fill arr_of_double with real nums (@type double)
  int arr_elems_count = 0;
  int input_info = 0;
  while (arr_elems_count < ARR_LENGTH) {
    input_info = scanf("%lf", &arr_of_double[arr_elems_count]);

    if (input_info == 0 || input_info == EOF) {
      break;
    }

    arr_elems_count += 1;
  }

  // create str like "csv: double, double, ...double"
  // @note !always set only read quantity of int in the arr_of_double!
  to_csv(str, arr_of_double, arr_elems_count);
  puts(str);

  return 0;
}

/**
 *  @brief count free chars in the string
 *
 *  @param {char *} str - pointer to the string
 *  @param {int} size_of_str - sizeof @link{str}
 *
 *  @return {int} - quantity of free chars in the string
 *
 *  @example
 *    str[4] = {a, b, \0}
 *      str_count_free_chars(str) => 1
 *    str[4] = {d, e, f, \0}
 *      str_count_free_chars(str) => 0
 */
int str_count_free_chars(const char *str, int size_of_str) {
  int str_len = (int)strlen(str);
  int free_chars = size_of_str - str_len;

  return free_chars;
}

/**
 *  @brief create str like "csv: double, double, ...double"
 *  @note !!! Impure function !!! It modifies current str (*str)
 *    Violation of "functional programming principles" => better to add
 *    @param str_size instead of using STR_LENGTH in the utility function
 *       @callback{str_count_free_chars}
 *
 *  @param {char *} str - pointer to the string
 *  @param {double[]} arr - array of real numbers
 *  @param {int} arr_length - array length (quantity of elems to use)
 *
 *  @return {int} - quantity of read real nums
 *
 *  @example
 *    arr{0.01, 5.43, 0.785, 11.9, \0} (4 nums), arr length = 20
 *      to_csv(arr, 4) => 4
 *        str => "csv: 0.01; 5.43; 0.79; 11.90"
 */
int to_csv(char *str, const double arr[], int arr_length) {
  int str_len = (int)strlen(str);

  char str_csv_template[] = "csv: ";
  int len_str_csv_template = (int)strlen(str_csv_template);

  char real_num_literal[] = "0.00; ";
  int len_real_num_literal = (int)strlen(real_num_literal);

  char real_num_literal_end[] = "0.00";
  int len_real_num_literal_end = (int)strlen(real_num_literal_end);

  // add template "csv: " to the str
  if (str_count_free_chars(str, STR_LENGTH) > len_str_csv_template) {
    strcpy(str, str_csv_template);
    str_len = (int)strlen(str);
  }

  // add real numbers from the @link{arr[]} to the @link{str}
  for (int i = 0; i < arr_length; i += 1) {
    // last real num ? => "...; .2f"
    if (i == arr_length - 1) {
      if (str_count_free_chars(str, STR_LENGTH) > len_real_num_literal_end) {
        snprintf(str + str_len, STR_LENGTH, "%.2f", arr[i]);
        str_len = (int)strlen(str);
        continue;
      }
    }

    // not last real num ? => "...; .2f; "
    if (str_count_free_chars(str, STR_LENGTH) > len_real_num_literal) {
      snprintf(str + str_len, STR_LENGTH, "%.2f; ", arr[i]);
      str_len = (int)strlen(str);
    }
  }

  return arr_length;
}
