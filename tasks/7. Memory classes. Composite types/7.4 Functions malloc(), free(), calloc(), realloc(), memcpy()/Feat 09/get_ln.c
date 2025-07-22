#include "./utils.h"

/**
 *  @brief Get the string data from the INPUT:
 *
 *  @note ! Impure function! Mutates outer @link{buffer} value! !
 *  @note Under the hood uses @callback{fgets} from the <string.h> and removes
 *    last '\n' properly
 *
 *  @param {char *buffer} buffer - array (static) to fill with got chars
 *  @param {size_t} max_len - size of @link{buffer}
 *
 *  @return {void} - nothing
 *
 *  @example
 *    char str[50] = {0};
 *    size_t max_len = 50;
 *    get_ln(str, max_len) =>
 *    INPUT:
 *    "Hello, World!)" => void
 *    str{'H', 'e', 'l', 'l', 'o', ',', ' ', 'W', 'o', 'r', 'l', 'd', '!', ')',
 *     \0}
 */
void get_ln(char *buffer, size_t max_len) {
  // get string data
  fgets(buffer, max_len - 1, stdin);

  // remove last '\n'
  char *ptr_n = strrchr(buffer, '\n');

  if (ptr_n != NULL) {
    *ptr_n = '\0';
  }
}
