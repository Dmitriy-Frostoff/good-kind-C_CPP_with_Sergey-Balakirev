#include "./utils.h"

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
