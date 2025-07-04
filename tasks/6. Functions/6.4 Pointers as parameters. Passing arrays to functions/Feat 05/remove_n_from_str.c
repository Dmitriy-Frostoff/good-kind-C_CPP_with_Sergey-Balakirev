#include "./utils.h"

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
