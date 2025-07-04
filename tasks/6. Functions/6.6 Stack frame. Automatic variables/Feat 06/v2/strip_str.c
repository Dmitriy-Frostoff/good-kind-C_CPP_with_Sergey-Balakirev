#include "./utils.h"

/**
 *  @brief Remove chars from the @link{str_template} in the @link{str}
 *
 *  @note !Impure function! It mutates the original @link{str} !
 *  @note !Implicit dependency on macro value STR_SIZE !!!
 *
 *  Under the hood @callback{strip_str} crates char str_copy[STR_SIZE], for
 *  copiing @link{str} and than replaces all the chars from the
 *    @link{str_template} in the @link{str_copy} with '\0' char, and than copy
 *  back chars to the original @link{str} with corrected terminated '\0' char
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
void strip_str(char *str, char *str_template) {
  size_t str_len = strlen(str);
  char str_copy[STR_SIZE] = {0};
  // count further
  size_t str_copy_len = 0;

  // create copy of the @link{str}
  if (str_copy_len <= str_len) {
    strcpy(str_copy, str);
  }

  // replace with '\0' all the chars from the
  //  @link{str_template} in the @link{str}
  // e.g. "Hello, World!" => "Hello\0 World!\0"
  // *ptr_str_copy = "H(ello\0 World!\0)"
  char *ptr_str_copy = strtok(str_copy, str_template);
  while (ptr_str_copy != NULL) {
    // update str_copy_len
    str_copy_len = strlen(ptr_str_copy);
    // copy part of @link{str} till the '\0'
    strcpy(str, ptr_str_copy);
    // set pointer after new word part for next chars copiing
    str += str_copy_len;
    // *ptr_str_copy = " (World!\0)"
    ptr_str_copy = strtok(NULL, str_template);
  }

  // ensure that pointer "str" after all terminated with '\0' char
  *str = '\0';
}
