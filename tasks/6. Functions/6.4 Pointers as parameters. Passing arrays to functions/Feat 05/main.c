/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191305/step/7?unit=1204293}
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_LENGTH 100
#define ARR_LENGTH 20

int get_data_csv(double arr[], unsigned int str_length, char *str);
void remove_n_from_str(char *str);
void print_real_numbers(const double arr[], int len_arr);

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

/**
 *  @brief remove '\n' char from the str
 *
 *  @param {char *} str - valid string
 *
 *  @example
 *     {d, a, t, e, \n, \0} => {d, a, t, e, \0, \0}
 */
void remove_n_from_str(char *str) {
  char *ptr_n = strrchr(str, '\n');
  if (ptr_n != NULL) {
    *ptr_n = '\0';
  }

  // reset pointer
  ptr_n = NULL;
}

/**
 *  @brief Get the data csv object
 *  @note !Not a pure function! It modifies @link{arr} and uses ARR_LENGTH from
 *    the global closure
 *
 *  @param {double[]} arr - array of real numbers
 *  @param {int} str_length - size of the @link{str}
 *  @param {char *} str - valid string like "csv: 0.56; -65.43; 0.1; 11.0"
 *
 *  @return {int} - quantity of the real numbers got from the @link{str}
 *  @throw - if string doesn't ыфешыан the template
 *
 *  @example
 *    double arr[20] = {0}, str = "csv: 0.56; -65.43; 0.1; 11.0" =>
 *      get_data_csv(arr, 100, str) => 4
 *        arr turns to {0.56, -65.43, 0.1, 11.0}
 */
int get_data_csv(double arr[], unsigned int str_length, char *str) {
  char *ptr_search = NULL;
  const char STR_DELIMETER_COLON[] = ":";
  const char STR_DELIMETER_SEMICOLON[] = ";";

  int num_count = 0;
  int arr_index = 0;

  // set ptr_search to the char right after ':'
  // *STR_DELIMETER_COLON == STR_DELIMETER_COLON[0]
  ptr_search = strchr(str, *STR_DELIMETER_COLON);
  if (ptr_search == NULL) {
    puts("Error: incorrect string template. Expected string like: \"csv: 0.56; "
         "-65.43; 0.1; 11.0\"");
    return 1;
  }
  ptr_search += 1;

  // fill arr with real numbers (@type double) from @link{str}
  while (num_count < ARR_LENGTH) {
    // ...: 0.56; => 0.56
    // @note ! atof('') => 0.0, atof(' 5') => 5.0
    double temp_num = atof(ptr_search);
    arr[arr_index] = temp_num;
    arr_index += 1;
    num_count += 1;

    // set pointer right after the ';' delimeter
    ptr_search = strchr(ptr_search, *STR_DELIMETER_SEMICOLON);
    if (ptr_search == NULL) {
      break;
    }
    ptr_search += 1;
  }

  // reset pointer
  ptr_search = NULL;

  return num_count;
}

/**
 *  @brief print to the terminal real numbers rounded to hundreds
 *
 *  @param {double[]} arr - array of real numbers
 *  @param {int} len_arr - array length (or quantity of elems to print)
 *
 *  @example
 *    arr[20] = {0.56, -65.43, 0.10, 11.00}
 *    print_real_numbers(arr, 4) => >>> 0.56 -65.43 0.10 11.00
 */
void print_real_numbers(const double arr[], int len_arr) {
  for (int i = 0; i < len_arr; i += 1) {
    if (i == len_arr - 1) {
      printf("%.2f", arr[i]);
      break;
    }
    printf("%.2f ", arr[i]);
  }
}
