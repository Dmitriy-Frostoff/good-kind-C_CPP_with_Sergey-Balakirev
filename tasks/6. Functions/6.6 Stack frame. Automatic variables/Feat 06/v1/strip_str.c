#include "./utils.h"

/**
 *  @brief Remove chars from the @link{str_template} in the @link{str}
 *
 *  @note !Impure function! It mutates the original @link{str} !
 *
 *  Under the hood @callback{strip_str} replaces all the chars from the
 *    @link{str_template} in the @link{str} with '\0' char, and than collapse
 *    '\0' (exclude last in the @link{str}) with next chars
 *
 *  @param {char *} str - string to mutate (remove chars)
 *  @param {const char *} str_template - template string with chars for removing
 *
 *  @return {void} - just mutates the original @link{str}
 *
 *  @example
 *    char str[100] = "!sc-lib@list.ru?";
 *    char str_template[20] = ".,-!?";
 *      strip_str(str, str_template) => void
 *      str{'s', 'c', 'l', 'i', 'b', '@', 'l', 'i', 's', 't', 'r', 'u', \0}
 */
void strip_str(char *str, const char *str_template) {
  size_t str_len = strlen(str);
  // last char is '\0'
  size_t str_last_index = str_len + 1;
  char is_zero_met = 0;
  //  replace all the chars from @link{str_template} in the @link{str}
  char *ptr_search = strpbrk(str, str_template);
  char *ptr_last_search = strrchr(str, '\0');
  while (ptr_search != NULL && ptr_search < ptr_last_search) {
    // replace the found char from the @link{str_template}
    *ptr_search = '\0';
    // go to the next match
    ptr_search = strpbrk(ptr_search + 1, str_template);
  }

  // reset pointer
  ptr_search = NULL;

  // collapse all the '\0' excluding last one
  for (int i = 0, j = i + 1; i <= str_len; i += 1, j += 1) {
    // current char is '\0' ?=> go further till char is not '\0'
    if (str[i] == '\0') {
      str_last_index -= 1;
      is_zero_met = 1;
      // skip '\0' str_last_index will protect correct string ending
      while (str[j] == '\0') {
        j += 1;
      }
    }

    if (is_zero_met) {
      // skip '\0' str_last_index will protect correct string ending
      while (str[j] == '\0') {
        j += 1;
      }
      // move @link{str} chars to the left (replace '\0')
      str[i] = str[j];
    }
  }

  // set correct '\0'
  str[str_last_index] = '\0';
}
