#include "./utils.h"

/**
 *  @brief Encode @link{str} of latin letters to Morze symbols
 *  @note !Impure function! Mutates @link{translated_str}
 *  Every index in the @link{LATIN_LETTERS_TEMPLATE} is correspondent to the
 *    @link{MORZE_SYMBOLS}
 *  Chars, that are absent in the @link{LATIN_LETTERS_TEMPLATE} will be skipped!
 *
 *  @param {const char *} str - valid string of latin chars, numbers, spaces and
 *    hyphens possible
 *  @param {size_t} str_len - @link{str} length
 *  @param {char *} translated_str - str to fill with Morze encoded symbols
 *  @param {size_t} translated_str_size - @link{translated_str} size (size of
 *    entire string array)
 *  @param {const char *} LATIN_LETTERS_TEMPLATE - template string of latin
 *    chars, numbers, spaces and hyphens for encoding
 *  @param {const size_t} LATIN_LETTERS_TEMPLATE_LENGTH -
 *    @link{LATIN_LETTERS_TEMPLATE} length
 *  @param {const char *[]} MORZE_SYMBOLS - array of template string chunks of
 *    Morze symbols
 *
 *  @example
 *    char str[50] = "Hello World, 42!))"
 *    size_t str_len = 18;
 *    char translated_str[50] = {0};
 *    size_t translated_str_size = 50;
 *    const char LATIN_LETTERS_TEMPLATE[] =
 *      " 0123456789abcdefghijklmnopqrstuvwxyz";
 *    size_t LATIN_LETTERS_TEMPLATE_LENGTH = 37;
 *    const char *MORZE_SYMBOLS[] = {
 *      "-...-", "-----", ".----", "..---", "...--", "....-", ".....", "-....",
 *      "--...", "---..", "----.", ".-",    "-...",  "-.-.",  "-..",   ".",
 *      "..-.",  "--.",   "....",  "..",    ".---",  "-.-",   ".-..",  "--",
 *      "-.",    "---",   ".--.",  "--.-",  ".-.",   "...",   "-",     "..-",
 *      "...-",  ".--",   "-..-",  "-.--",  "--.."};
 *    translate_str(str, str_len, translated_str, translated_str_size,
 *      LATIN_LETTERS_TEMPLATE, LATIN_LETTERS_TEMPLATE_LENGTH, MORZE_SYMBOLS) =>
 *      => void
 *      translated_str{
 *        ".... . .-.. .-.. --- -...- .-- --- .-. .-.. -.. -...- ....- ..---"
 *      }
 *      @note ! chars ",!))" are absent in the Morze symbols template and that's
 *      why were skipped !
 */
void translate_str(const char *str, size_t str_len, char *translated_str,
                   size_t translated_str_size,
                   const char *LATIN_LETTERS_TEMPLATE,
                   const size_t LATIN_LETTERS_TEMPLATE_LENGTH,
                   const char *MORZE_SYMBOLS[]) {
  for (size_t i = 0; i < str_len; i += 1) {
    // index as relationship between latin letter and Morze symbol
    int index = -1;

    // get @link{index} of latin letter template correspondent to current letter
    for (int j = 0; j < LATIN_LETTERS_TEMPLATE_LENGTH; j += 1) {
      if (str[i] == LATIN_LETTERS_TEMPLATE[j]) {
        index = j;
        break;
      }
    }

    // no match ? => skip current char and go further
    if (index == -1) {
      continue;
    }

    // add correspondent Morze symbol if enough space
    if (translated_str_size -
            (strlen(translated_str) + strlen(MORZE_SYMBOLS[index])) >
        0) {
      strcat(translated_str, MORZE_SYMBOLS[index]);
    }

    // not last letter in the @link{str} ? => add " " as separator
    if (i != str_len - 1) {
      // check for enough space
      if (translated_str_size - (strlen(translated_str) + strlen(" ")) > 0) {
        strcat(translated_str, " ");
      }
    }
  }
}
