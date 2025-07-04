#include "./utils.h"

/**
 *  @brief Remove last '\n' from the string
 *
 *  @param {char *} str - pointer to the valid string
 *
 *  @return {int} - 0, everything is OK
 *  @throw if empty string pointer was produced and returns exit code 1
 *
 *  @example
 *    char str[20] = {H, e, l, l, o,  , w, o, r, l, d, !, \n, \0};
 *      remove_str_last_n(str) => 0
 *      str{H, e, l, l, o,  , w, o, r, l, d, !, \0}
 */
int remove_str_last_n(char *str) {
  if (str == NULL) {
    puts("Error: empty string pointer");
    return 1;
  }

  char *ptr_n = strrchr(str, '\n');
  if (ptr_n != NULL) {
    *ptr_n = '\0';
  }

  return 0;
}
