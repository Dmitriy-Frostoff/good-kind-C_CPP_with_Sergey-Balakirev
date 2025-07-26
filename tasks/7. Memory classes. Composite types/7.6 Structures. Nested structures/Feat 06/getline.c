#include "./utils.h"

/**
 *  @brief Get the string data from the INPUT: into the @link{buffer} and remove
 *  last '\n'
 *
 *  @note ! Impure function !
 *  - mutates the outer @link{buffer}
 *
 *  @param {char *} buffer - array to save the INPUT: string data
 *  @param {size_t} max_len - size of @link{buffer}
 *
 *  @example
 *    char buffer[50] = {0};
 *    size_t max_len = 50;
 *
 *    getline(buffer, max_len) =>
 *    INPUT:
 *    "Hello" => void
 *    buffer{'H', 'e', 'l', 'l', 'o', \0}
 *
 */
void getline(char *buffer, size_t max_len) {
  // get the input data
  fgets(buffer, max_len - 1, stdin);

  // get last '\n'
  char *ptr_n = strrchr(buffer, '\n');

  // replace last '\n' with '\0'
  if (ptr_n != NULL) {
    *ptr_n = '\0';
  }
}
