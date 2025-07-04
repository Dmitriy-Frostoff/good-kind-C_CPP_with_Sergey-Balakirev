#include "./utils.h"

/**
 *  @brief Function for comparison char codes of chars
 *
 *  Scheme:
 *  A and B are "0...9" and char code A < char code B are => 1
 *  A is "0...9", B is a letter or any char out of "0...9" => 1
 *    @note even if char code A > char code B
 *  A is not "0...9" and B is => 0
 *    @note even if char code A < char code B
 *  char code A < char code B => 1
 *
 *  @param {const char} A - char for comparing
 *  @param {const char} B - char for comparing
 *
 *  @return {int} - 1, @link{A} < @link{B}
 *  @return {int} - 0, @link{A} > @link{B}
 *
 *  @example
 *    match_ab('0', '9') => 1
 *    match_ab('9', '0') => 0
 *    match_ab('0', 'A') => 1
 *    match_ab('0', 'a') => 1
 *    match_ab('0', '-') => 1
 *      despite that char code '0' is 48, char code of '-' is 45
 *    match_ab(' ', '0') => 0
 *      despite that char code ' ' is 32, char code of '0' is 48
 *    match_ab('A', 'a') => 1
 *      'A' => 65, 'a' => 97
 */
int match_ab(const char A, const char B) {
  // A && B are '0'...'9'
  if (((A >= CHAR_CODE_ZERO && A <= CHAR_CODE_NINE) &&
       (B >= CHAR_CODE_ZERO && B <= CHAR_CODE_NINE)) &&
      A < B) {
    return 1;
  }

  // A '0' ... '9' and B is an another char
  // (even if B < A, e.g. B is '-' => 45, A is '0' => 48)
  if ((A >= CHAR_CODE_ZERO && A <= CHAR_CODE_NINE) &&
      !(B >= CHAR_CODE_ZERO && B <= CHAR_CODE_NINE)) {
    return 1;
  }

  // A is not '0' ... '9' and B is
  // (even if A < B, e.g. A is ' ' => 32, A is '0' => 48)
  if (!(A >= CHAR_CODE_ZERO && A <= CHAR_CODE_NINE) &&
      (B >= CHAR_CODE_ZERO && B <= CHAR_CODE_NINE)) {
    return 0;
  }

  // A and B are just chars (both not "0...9")
  if (A < B) {
    return 1;
  }

  return 0;
}
