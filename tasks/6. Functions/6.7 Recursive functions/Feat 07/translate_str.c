#include "./utils.h"
#include "config.h"

/**
 *  @brief Decode @link{str} of Morze symbols to latin letters (to upper case)
 *  @note !Impure function! Mutates @link{translated_str}
 *  @note !Depends on predefined macros @link{STR_SIZE} (same as @link{str}
 *  uses)!
 *  Every index in the @link{MORZE_SYMBOLS} is correspondent to the
 *    @link{LATIN_LETTERS_TEMPLATE}
 *  Chars, that are absent in the @link{LATIN_LETTERS_TEMPLATE} will be skipped!
 *
 *  @param {const char *} str - valid string of Morze symbols
 *  @param {const size_t} str_len - @link{str} length
 *  @param {char *} translated_str - str to fill with Morze decoded symbols
 *  @param {size_t} translated_str_size - @link{translated_str} size (size of
 *    entire string array)
 *  @param {const char *} LATIN_LETTERS_TEMPLATE - template string of latin
 *    chars, numbers, spaces and hyphens for encoding
 *  @param {const char *[]} MORZE_SYMBOLS - array of template string chunks of
 *    Morze symbols
 *  @param {const size_t} MORZE_SYMBOLS_SIZE - size of array of
 *    @link{MORZE_SYMBOLS} (i.e. rows quantity)
 *  @param {char} CHAR_SEPARATOR - separator between every of the
 *    @link{MORZE_SYMBOLS}
 *
 *  @example
 *    char str[100] =
 *      ".... . .-.. .-.. --- -...- .-- --- .-. .-.. -.. -...- ....- ..---"
 *    size_t str_len = 65;
 *    char translated_str[100] = {0};
 *    size_t translated_str_size = 100;
 *    const char LATIN_LETTERS_TEMPLATE[] =
 *      " 0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
 *    const char *MORZE_SYMBOLS[] = {
 *      "-...-", "-----", ".----", "..---", "...--", "....-", ".....", "-....",
 *      "--...", "---..", "----.", ".-",    "-...",  "-.-.",  "-..",   ".",
 *      "..-.",  "--.",   "....",  "..",    ".---",  "-.-",   ".-..",  "--",
 *      "-.",    "---",   ".--.",  "--.-",  ".-.",   "...",   "-",     "..-",
 *      "...-",  ".--",   "-..-",  "-.--",  "--.."};
 *    const size_t MORZE_SYMBOLS_SIZE = 37;
 *    char CHAR_SEPARATOR = ' ';
 *    translate_str(str, str_len, translated_str, translated_str_size,
 *      LATIN_LETTERS_TEMPLATE, MORZE_SYMBOLS, MORZE_SYMBOLS_SIZE,
 *      CHAR_SEPARATOR) => void
 *      translated_str{
 *        "HELLO WORLD 42"
 *      }
 *      @note The got string is upper case and without punctuation
 *      marks (cause they're absent in the @link{MORZE_SYMBOLS})
 */
void translate_str(const char *str, const size_t STR_LEN, char *translated_str,
                   size_t translated_str_size,
                   const char *LATIN_LETTERS_TEMPLATE,
                   const char *MORZE_SYMBOLS[], const size_t MORZE_SYMBOLS_SIZE,
                   char CHAR_SEPARATOR) {
  //  copy the @link{str} to prevent mutation
  char str_copy[STR_SIZE] = {0};
  strcpy(str_copy, str);
  char *ptr_str_copy = NULL;

  // split @link{str} via separator (e.g. space " ")
  // @note every first occurence of the separator is just replaced with '\0'
  // char
  ptr_str_copy = strtok(str_copy, &CHAR_SEPARATOR);

  // empty string ? => return
  // @note ! strtok("Hello", ' ') => "Hello", not NULL !!!
  if (ptr_str_copy == NULL) {
    return;
  }

  // split string by separator (one by one) and step all over the got substring
  while (ptr_str_copy != NULL) {
    for (size_t i = 0; i < MORZE_SYMBOLS_SIZE; i += 1) {
      if (strcmp(ptr_str_copy, MORZE_SYMBOLS[i]) == 0) {
        // check for enough space to copy letter from
        // @link{LATIN_LETTERS_TEMPLATE} to @link{translated_str}
        // @note strlen(translated_str) + 1 => + 1 is plus one letter from
        // @link{LATIN_LETTERS_TEMPLATE}
        if (translated_str_size - (strlen(translated_str) + 1) > 1) {
          strncat(translated_str, &LATIN_LETTERS_TEMPLATE[i], 1);
        }
        break;
      }
    }

    // go to the next substring
    // @note after first setup of 'strtok' to 'str_copy', !always! use NULL as
    // a pointer !
    ptr_str_copy = strtok(NULL, &CHAR_SEPARATOR);
  }
}
