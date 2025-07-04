#include "./utils.h"

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
