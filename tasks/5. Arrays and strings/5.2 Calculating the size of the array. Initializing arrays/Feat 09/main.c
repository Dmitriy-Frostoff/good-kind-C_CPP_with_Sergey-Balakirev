/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191292/step/11?unit=1204280}
 *
 * There's declared array with the name 'marks' of type 'short'. It's exist but
 * hidden in the another code. Count the arithmetic mean of the 'marks' array
 * and print to the console counted mean accurated to hundredths
 *
 */

#include <stdio.h>

int main(void) {
  unsigned char marks_length = sizeof(marks) / sizeof(*marks);
  double sum = 0;
  double avg_value = 0;

  // avg = sum_of_arr_nums / arr_length
  for (unsigned char i = 0; i < marks_length; i += 1) {
    sum += marks[i];
  }

  avg_value = sum / (double)marks_length;

  printf("%.2f", avg_value);

  return 0;
}
