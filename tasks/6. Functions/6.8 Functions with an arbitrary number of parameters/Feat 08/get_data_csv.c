#include "./utils.h"

/**
 *  @brief Get the nums ( @type{double} ) from the @link{str}, save them to the
 *  @link{arr} and return quantity of the added nums
 *
 *  @note ! Impure function! Mutates the @link{arr} !
 *
 *  @param {double []} arr - array to fill with excluded of the @link{str} nums
 *  @param {const size_t} SIZE_OF_ARR - entire size of @link{arr}
 *  @param {char *} str - valid CSV style string like:
 *    'csv: <num 1>; <num 2>; ...; <num N>'
 *
 *  @return {int} - quantity of added to the @link{arr} nums ( @type{double} )
 *    or -1 if invalid CSV string was produced
 *  @throw - if invalid CSV string was produced
 *
 *  @example
 *    char str[100] = "csv: 0.56; -65.43; 0.1; 11.0";
 *    size_t str_len = 100;
 *    double doubles_arr[20] = {0};
 *    size_t doubles_arr_size = 20;
 *    get_data_csv(arr, doubles_arr_size, str) => 4
 *      doubles_arr{0.56; -65.43; 0.1; 11.0}
 */
int get_data_csv(double arr[], const size_t SIZE_OF_ARR, char *str) {
  const char DELIMETER_COLON = ':';
  const char DELIMETER_SEMICOLON = ';';
  char *ptr_str = str;
  int nums_count = 0;

  // check that @link{DELIMETER_COLON} present
  ptr_str = strchr(str, DELIMETER_COLON);

  if (ptr_str == NULL) {
    puts("Error: 'get_data_csv' func. Expected csv style string like: 'csv: "
         "<num 1>; <num 2>; ...; <num N>'");
    return -1;
  }

  // step to the char right after @link{DELIMETER_SEMICOLON} over and over
  while (ptr_str != NULL) {
    // step to the next char after delimeter
    ptr_str += 1;

    if (ptr_str != NULL) {
      arr[nums_count] = atof(ptr_str);
      // increase counter and index simultaneously
      nums_count += 1;

      // check that index not out of the array size
      if (nums_count < SIZE_OF_ARR) {
        // step to the next @link{DELIMETER_SEMICOLON}
        ptr_str = strchr(ptr_str, DELIMETER_SEMICOLON);
        continue;
      }

      // @link{arr} is full ? =>
      return nums_count;
    }
  }

  // no more @link{DELIMETER_SEMICOLON} ? =>
  return nums_count;
}
