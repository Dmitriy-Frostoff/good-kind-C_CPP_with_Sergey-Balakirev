/**
 *  The task description is at
 *  @link{https://stepik.org/lesson/1191314/step/11?unit=1204302}
 *
 */

#include "./config.h"
#include "./utils.h"

int main(void) {
  WORDS_ARR words = {0};
  int read_words = 0;
  int count_words = 0;

  // get words from the INPUT:
  read_words = get_input_data(words, WORDS_QUANTITY, " ");

  // check and count correct words
  count_words = get_correct_words(words, read_words, is_correct);

  // print @link{count_words}
  printf("%d", count_words);

  return 0;
}
