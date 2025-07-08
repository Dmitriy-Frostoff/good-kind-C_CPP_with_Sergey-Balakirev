#include "./utils.h"

/**
 *  @brief Get the string data from the input
 *  @note "Impure function! Mutates the @link{str}"
 *
 *  @param {char *} str - string array
 *  @param {size_t} str_size - size of @link{str}
 *
 *  @throw if @link{str} is empty
 *
 *  @example
 *    char str[20] = {0};
 *    size_t str_sizegth = 20;
 *    get_string_data(str, str_sizegth) =>
 *    INPUT:
 *    "Hello World" => void
 *    str{H, e, l, l, o,  , W, o, r, l, d, \0}
 */
void get_string_data(char *str, size_t str_size) {
  fgets(str, str_size - 1, stdin);

  if (strlen(str) == 0) {
    puts("Error: empty string was produced");
    return;
  }
}
