/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191301/step/8?unit=1204289}
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_SIZE 250
#define MAX_MARKS_QUANTITY 20

int main(void) {
  char str[STR_SIZE] = {0};
  const char CHAR_DELIMETER_SEMICOLON[] = ":";
  const char CHAR_DELIMETER_COMMA[] = ",";
  int marks_quantity = 0;
  int marks_sum = 0;
  double average_marks_sum = 0;

  char *ptr_search = NULL;

  // get the input string
  // template >>>
  //  "<surname>: (int)<mark>, (int)<mark>, (int)<mark>, ...(int)<mark>"
  if (fgets(str, sizeof(str) - 1, stdin) == NULL) {
    puts("expected string like: '<surname>: (int)<mark>, (int)<mark>, "
         "(int)<mark>, ...(int)<mark>'");
    return 0;
  }

  // remove '\n' from the 'str'
  ptr_search = strrchr(str, '\n');
  if (ptr_search != NULL) {
    *ptr_search = '\0';
  }
  ptr_search = NULL;

  // set pointer to the next char after ':' in the 'str'
  ptr_search = strchr(str, CHAR_DELIMETER_SEMICOLON[0]);
  ptr_search += 1;

  if (ptr_search == NULL) {
    puts("expected string like: '<surname>: (int)<mark>, (int)<mark>, "
         "(int)<mark>, ...(int)<mark>'");
    return 0;
  }
  //  get the marks_sum and marks_quantity
  while (ptr_search != NULL) {
    // end of 'str' ? => break
    if (*ptr_search == '\0' || *ptr_search == '\n') {
      break;
    }

    int current_mark = atoi(ptr_search);

    // incorrect 'number' or just 'char' ? => set 'pointer' forward
    if (current_mark == 0) {
      ptr_search += 1;
      continue;
    }

    marks_sum += current_mark;
    marks_quantity += 1;

    if (marks_quantity >= MAX_MARKS_QUANTITY) {
      break;
    }

    // set pointer to the next char after ',' in the 'str'
    ptr_search = strchr(ptr_search, CHAR_DELIMETER_COMMA[0]);

    if (ptr_search != NULL) {
      ptr_search += 1;
    }
  }

  average_marks_sum = (double)marks_sum / (double)marks_quantity;

  printf("%.3f\n", average_marks_sum);

  return 0;
}
