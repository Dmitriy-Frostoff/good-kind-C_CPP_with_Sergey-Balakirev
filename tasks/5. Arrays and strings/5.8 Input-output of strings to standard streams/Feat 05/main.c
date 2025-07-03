/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191298/step/7?unit=1204286}
 *
 */

#include <stdio.h>

#define WORDS_QUANTITY 6
#define WORD_LENGTH 31

int main(void) {
  char data[WORDS_QUANTITY][WORD_LENGTH];
  char word_counter = 0;

  while (word_counter < WORDS_QUANTITY) {
    // 30s => WORD_LENGTH - 1 (31 - 1)
    if (scanf("%30s", data[word_counter]) != 1) {
      printf("expected word not greater than 30 characters\n");
      return 0;
    }
    word_counter += 1;
  }

  for (char i = 0; i < WORDS_QUANTITY; i += 1) {
    if (data[i][0] == 'g' || data[i][0] == 'G') {
      printf("%s ", data[i]);
    }
  }
}
