#include "./utils.h"

/**
 *  @brief Get the quantity of words, that passed @callback{filter} check
 *
 *  @note Implicit dependency of:
 *    - @link{WORD_LENGTH}
 *    - callback custom type @link{FUNC_CORRECT}
 *
 *  @param {const char (*)[WORD_LENGTH]} count_words - 2d array of words
 *  @param {FUNC_CORRECT} filter - @see{is_correct} callback
 *
 *  @return {int} - quantity of words, that passed @callback{filter} check
 *
 *  @example
 *    char words[20][50] = {"God", "RA"};
 *    int count_words = 2;
 *    get_correct_words(words, count_words, is_correct) => 1
 *      "RA" turns into "ra" and contains etalon string "ra"
 *
 */
int get_correct_words(const char (*words)[WORD_LENGTH], int count_words,
                      FUNC_CORRECT filter) {
  int passed_check_words = 0;

  for (int i = 0; i < count_words; i += 1) {
    if (filter(words[i])) {
      passed_check_words += 1;
    }
  }

  return passed_check_words;
}
