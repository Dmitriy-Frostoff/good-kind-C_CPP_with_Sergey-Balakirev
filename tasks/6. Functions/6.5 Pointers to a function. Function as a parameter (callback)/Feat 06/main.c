/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191306/step/8?unit=1204294}
 *
 */

#include <stdio.h>
#include <string.h>

#define STR_SIZE 100
#define CHAR_CODE_ZERO 48
#define CHAR_CODE_NINE 57

int get_string_data(char *str, size_t sizeof_str);
int remove_str_last_n(char *str);
int match_ab(char A, char B);
void sort_string(char *str, size_t max_len,
                 int (*compare_callback)(const char, const char));

int main(void) {
  char str[STR_SIZE] = {0};
  size_t str_len = 0;

  // get the string from the input
  if (get_string_data(str, sizeof(str)) == 1) {
    return 1;
  }

  // remove '\n' from the end of string
  if (remove_str_last_n(str)) {
    return 1;
  }

  // get actual @link{str} length
  str_len = strlen(str);

  sort_string(str, str_len, match_ab);

  // print the sorted @link{str}
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

/**
 *  @brief Sort @link{str} chars via chosen callback @link{match_ab}
 *
 *  @note !Impure function! Mutates the original @link{str}
 *  @note Sorting function is based on the "Selection Sort" algorithm
 *
 *  @param {char *} str - valid string for sorting its chars
 *  @param {size_t} max_len - quantity of chars int the @link{str}
 *    (not the entire char str[] size!)
 *  @param {int (*)(const char a, const charb)} match_ab - callback for
 *    comparing chars logic
 *  @return {void} - nothing to return
 *
 *  @example
 *    char str[100] = "Phone number: 7845037856221";
 *    max_len = 27;
 *    compare_callback - match_ab @see{match_ab}
 *      sort_string(str, max_len, match_ab) =>
 *        "0122345567788  :Pbeehmnnoru"
 */
void sort_string(char *str, size_t max_len,
                 int (*compare_callback)(const char, const char)) {
  size_t current_index;
  // fix for case if "someone" pass the entire size of @link{str}
  //  instead of str_len
  max_len = strlen(str);

  for (size_t i = 0; i < max_len - 1; i += 1) {
    current_index = i;

    for (size_t j = i + 1; j < max_len; j += 1) {
      if (!match_ab(str[current_index], str[j])) {
        current_index = j;
      }
    }

    // index is not the same as at the begining ? =>
    if (current_index != i) {
      // swap str values at current_index and i
      char temp = str[current_index];
      str[current_index] = str[i];
      str[i] = temp;
    }
  }
}
