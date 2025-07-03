/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191298/step/5?unit=1204286}
 *
 */

#include <stdio.h>

#define WORDS_QUANTITY 5
#define WORD_LENGTH 10

int main(void) {
  char data[WORDS_QUANTITY][WORD_LENGTH];
  char word_counter = 0;

  while (word_counter < WORDS_QUANTITY) {
    // 9s => WORD_LENGTH - 1 (10 - 1)
    if (scanf("%9s", data[word_counter]) != 1) {
      printf("expected word with 9 characters length\n");
      return 0;
    }
    word_counter += 1;
  }

  for (char i = 0; i < WORDS_QUANTITY; i += 1) {
    printf("[%s]\n", data[i]);
  }
}
