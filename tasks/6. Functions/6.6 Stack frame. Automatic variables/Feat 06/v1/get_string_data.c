#include "./utils.h"

/**
 *  @brief Get the string data from the input
 *
 *  @param {char *} str - string data
 *  @param {size_t} sizeof_str - string size
 *
 *  @return {int} - 0, everything OK
 *  @throw if empty data was produced and retrun exit code 1
 *
 *  @example
 *    char str[20] = {0};
 *      get_string_data(str, sizeof(str)) =>
 *      INPUT:
 *      "Hello world!" => 0
 */
int get_string_data(char *str, size_t sizeof_str) {
  if (fgets(str, sizeof_str - 1, stdin) == NULL) {
    puts("Error: empty string data");
    return 1;
  }

  return 0;
}
