/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191306/step/5?unit=1204294}
 *
 */

#include <locale.h>
#include <stdio.h>
#include <string.h>

#define STR_SRC_SIZE 100
#define STR_DST_SIZE 20

#define CHAR_CODE_A 65
#define CHAR_CODE_Z 90
#define CHAR_CODE_A_LOW 97
#define CHAR_CODE_Z_LOW 122
// All RU letters А-Яа-я are of two bytes 0xD0 + ... or 0xD1 + ...
// 0xD0 0x90 'А', 0xD0 0xAF 'Я'
// 0xD0 0xB0 'а', 0xD1 0x8F 'я', 0xD0 == 208, 0xD1 == 209
#define CHAR_CODE_RU_PREFIX_V1 208
#define CHAR_CODE_RU_PREFIX_V2 209

int get_string_data(char *str, size_t sizeof_str);
int remove_str_last_n(char *str);
int check_latin_char(char LETTER);
void copy_string(char *dst, size_t max_len_dst, const char *src,
                 int (*spell_callback)(const char LETTER));

int main(void) {
  // for proper terminal handling of 'ru' chars
  setlocale(LC_ALL, ".UTF-8");

  char str[STR_SRC_SIZE] = {0};
  char str2[STR_DST_SIZE] = {0};

  // get the string from the input
  if (get_string_data(str, sizeof(str)) == 1) {
    return 1;
  }

  // remove '\n' from the end of string
  if (remove_str_last_n(str)) {
    return 1;
  }

  // copy str to str2
  copy_string(str2, sizeof(str2), str, check_latin_char);

  // print to the console str2
  puts(str2);

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

/**
 *  @brief Copy (byte to byte) chars from one string to another
 *  if @callback ' s check returns 1 (true)
 *
 *  @note UTF-8 usage expected!!!
 *
 *  @param {char *} dst - string to copy data in
 *  @param {size_t} max_len_dst - sizeof @link{dst} string
 *  @param {const char *} src - source string for checking and copiing data
 *  @param {int (*)(const char LETTER)} spell_callback - callback for checking
 *   data
 *
 *  @return {void} - nothing to return
 *
 *  @example
 *    char src[100] = "HelloСергею Балакиреву и всем остальным ученикам!";
 *    char dst[20] = {0};
 *    sizeof(dst) == 20;
 *    @callback @link{check_latin_char} => not EN alphabet char ? => 1 : 0
 *      copy_string(dst, sizeof(dst), src, check_latin_char) =>
 *      Сергею Бал (20 chars + '\0' in the end)
 *      RU chars are of TWO bytes (e.g. 0xD0 0x90 'А', 0xD1 0x8F 'я'), but
 *      always start from 0xD0(208) or 0xD1(209)
 */
void copy_string(char *dst, size_t max_len_dst, const char *src,
                 int (*spell_callback)(const char LETTER)) {
  size_t index = 0;
  int dst_char_count = 0;

  while ((dst_char_count < max_len_dst) && src[index] != '\0') {
    // pass the check ? => step further
    if (spell_callback(src[index])) {
      // copy current RU two bytes char to the @link{dst}
      // first byte is like RU letter start ? =>
      if ((src[index] == CHAR_CODE_RU_PREFIX_V1) ||
          (src[index] == CHAR_CODE_RU_PREFIX_V2)) {
        // is there at least two free chars ?
        if (max_len_dst - dst_char_count > 2) {
          strncat(dst, &src[index], 2);
          dst_char_count += 2;
          index += 2;
          continue;
        }
      }

      // is there at least one free char ?
      if (max_len_dst - dst_char_count > 1) {
        // copy another chars
        strncat(dst, &src[index], 1);
        dst_char_count += 1;
      }
    }
    index += 1;
  }

  // add '\0' to the end of the string
  // if a string with a lot of spaces or of unsupported chars was produced =>
  //  dst_char_count != strlen(str)
  dst[dst_char_count] = '\0';
}
