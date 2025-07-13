#include "./utils.h"

/**
 *  @brief Remove last '\n' from the @link{str}
 *  @note !Impure function! Mutates the @link{str}
 *
 *  @param {char *} str - valid string to remove '\n'
 *
 *  @example
 *    char str[20] = {H, e, l, l, o,  , W, o, r, l, d, \n, \0}
 *    remove_last_n(str) => void
 *      str{H, e, l, l, o,  , W, o, r, l, d, \0}
 */
void remove_last_n(char *str) {
  char *ptr_n = strrchr(str, '\n');

  if (ptr_n != NULL) {
    *ptr_n = '\0';
  }
}
