/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191308/step/8?unit=1204296}
 *
 */

#include "./config.h"
#include "./utils.h"

int main(void) {
  char str[STR_SIZE] = {0};
  size_t str_size = sizeof(str);
  size_t str_len;

  // latin letters and symbols and their corresponding Morze symbols
  const char ALPHABET_LETTERS[] = " 0123456789abcdefghijklmnopqrstuvwxyz";
  size_t ALPHABET_LETTERS_LENGTH = strlen(ALPHABET_LETTERS);
  const char *MORZE_SYMBOLS[] = {
      "-...-", "-----", ".----", "..---", "...--", "....-", ".....", "-....",
      "--...", "---..", "----.", ".-",    "-...",  "-.-.",  "-..",   ".",
      "..-.",  "--.",   "....",  "..",    ".---",  "-.-",   ".-..",  "--",
      "-.",    "---",   ".--.",  "--.-",  ".-.",   "...",   "-",     "..-",
      "...-",  ".--",   "-..-",  "-.--",  "--.."};

  char translated_str[STR_SIZE] = {0};
  size_t translated_str_len;

  // get the string data
  get_string_data(str, str_size);

  // remove last '\n' from the @link{str}
  remove_last_n(str);

  // set @link{str} to low case
  str_to_low(str);

  // get actual @link{str} length
  str_len = strlen(str);
  translated_str_len = str_size;

  // translate @link{str} into Morze symbols
  translate_str(str, str_len, translated_str, translated_str_len,
                ALPHABET_LETTERS, ALPHABET_LETTERS_LENGTH, MORZE_SYMBOLS);

  //  print Morze coded string
  puts(translated_str);

  return 0;
}
