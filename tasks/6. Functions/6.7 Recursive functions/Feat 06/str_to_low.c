#include "./utils.h"

/**
 *  @brief Set all the @link{str} chars to lower case
 *  @note !Impure funtion! Mutates the @link{str}
 *  Chars, that are not letters won't be modified
 *
 *  @param {char *} str - valid string
 *
 *  @example
 *    str[20] = "Hello, World-42/qQ";
 *    str_to_low(str) => "hello, world-42/qq"
 *    str[20] = "Hello\0, World";
 *    str_to_low(str) => "hello"
 *      because '\0' is interpreted as 'end of string' char
 */
void str_to_low(char *str) {
  while (*str != '\0') {
    *str = (char)tolower(*str);
    str += 1;
  }
}
