#include "./utils.h"

/**
 *  @brief check if current char is not a latin letter
 *
 *  @param {char} letter - any letter (EN or RU) or char
 *
 *  @return {int} - 1, char is not latin
 *  @return {int} - 0, char is latin
 *
 *  @example
 *    char letter = 'q';
 *      check_latin_char(letter) => 1
 *    char letter = 'ж';
 *      check_latin_char(letter) => 0
 */
int check_latin_char(const char LETTER) {
  // ASCII charCode 65 = 'A', charCode 90 = 'Z'
  // charCode 97 = 'a', charCode 122 = 'z'
  // not a latin char ? => 1
  if (!((LETTER >= CHAR_CODE_A && LETTER <= CHAR_CODE_Z) ||
        (LETTER >= CHAR_CODE_A_LOW && LETTER <= CHAR_CODE_Z_LOW))) {
    return 1;
  }
  return 0;
}
