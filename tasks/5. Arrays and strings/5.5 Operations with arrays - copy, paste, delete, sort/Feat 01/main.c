/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191295/step/3?unit=1204283}
 *
 */

#include <stdio.h>

int main(void) {
  short ar[10];
  short marks[5];
  char count = 0;
  char input_nums_quantity = 0;
  char sz_ar = sizeof(ar) / sizeof(*ar);
  char marks_length = sizeof(marks) / sizeof(*marks);

  while (count < sz_ar && scanf("%hd", &ar[count]) == 1) {
    count += 1;
  }

  // save the count variable value
  input_nums_quantity = count;

  /**
   * @example
   *    1 2 3 4 5 6 7 8 9 10 11 12 13 => marks{10, 9, 8, 7, 6}
   *    -1 -2 -3 -4 => marks{-4 -3 -2 -1}
   *      input_nums_quantity = count = 4, marks_length = 5
   *    1 => marks{1}
   *      input_nums_quantity = count = 2, marks_length = 5
   *    1 2 3 4 5 => marks{5, 4, 3, 2, 1}
   *      input_nums_quantity = count = 5, marks_length = 5
   */
  for (char i = 0; i < input_nums_quantity && i < marks_length; i += 1) {
    // max count = 10, ar length = 10, ar max index = 9 [0...9]
    marks[i] = ar[count - 1];
    printf("%d ", marks[i]);
    count -= 1;
  }

  return 0;
}
