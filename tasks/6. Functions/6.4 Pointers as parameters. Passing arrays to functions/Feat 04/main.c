/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191305/step/6?unit=1204293}
 *
 */

#include "./config.h"
#include "./to_csv.h"

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
