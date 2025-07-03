/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191298/step/6?unit=1204286}
 *
 */

#include <stdio.h>

#define WORDS_QUANTITY 6
#define WORD_LENGTH 21

int main(void) {
  char data[WORDS_QUANTITY][WORD_LENGTH];
  char word_counter = 0;

  while (word_counter < WORDS_QUANTITY) {
    // 20s => WORD_LENGTH - 1 (21 - 1)
    if (scanf("%20s", data[word_counter]) != 1) {
      printf("expected word with not greater than 20 characters\n");
      return 0;
    }
    word_counter += 1;
  }

  for (char i = WORDS_QUANTITY - 1; i >= 0; i -= 1) {
    printf("%s ", data[i]);
  }
}
