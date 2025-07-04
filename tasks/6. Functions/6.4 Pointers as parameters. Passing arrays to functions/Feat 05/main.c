/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191305/step/7?unit=1204293}
 *
 */

#include "./config.h"
#include "./utils.h"

/**
 *  @brief get the string from the input to the array and than print to the
 *    console the array numbers
 *
 *  @throw if empty string was produced
 *
 *  @example
 *    "csv: 0.56; -65.43; 0.1; 11.0" => 0.56 -65.43 0.10 11.00
 */
int main(void) {
  char str[STR_LENGTH] = {0};
  int len_str = (int)sizeof(str);
  double arr_of_double[ARR_LENGTH] = {0};
  int len_arr_of_double = (int)sizeof(arr_of_double) / *arr_of_double;

  // get the string like: "csv: 0.56; -65.43; 0.1; 11.0"
  if (fgets(str, sizeof(str) - 1, stdin) == NULL) {
    puts("Error: empty string");
    return 1;
  }

  // remove '\n' from the @link{str}
  remove_n_from_str(str);

  // get actual nums quantity in the @link{arr_of_double}
  len_arr_of_double = get_data_csv(arr_of_double, len_str, str);

  // print real numbers of @link{arr_of_double} to the terminal
  print_real_numbers(arr_of_double, len_arr_of_double);

  return 0;
}
