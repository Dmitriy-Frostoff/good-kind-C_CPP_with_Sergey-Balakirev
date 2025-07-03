/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191307/step/8?unit=1204295}
 *
 */

#include <stddef.h>
#include <stdio.h>
#include <string.h>

#define STR_SIZE 100
#define STR_TEMPLATE_SIZE 20

int get_string_data(char *str, size_t sizeof_str);
int remove_str_last_n(char *str);
void strip_str(char *str, char *str_template);

int main(void) {
  char str[STR_SIZE] = {0};
  char str2[STR_TEMPLATE_SIZE] = ".,-!?";

  // get the string from the input
  if (get_string_data(str, sizeof(str)) == 1) {
    return 1;
  }

  // remove '\n' from the end of string
  if (remove_str_last_n(str)) {
    return 1;
  }

  // mutate the @link{str} => remove all @link{str2} chars
  strip_str(str, str2);

  // print to the console str
  puts(str);

  return 0;
}

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
