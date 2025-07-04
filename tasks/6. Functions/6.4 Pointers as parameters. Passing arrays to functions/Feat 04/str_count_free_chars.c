#include "./to_csv.h"

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
