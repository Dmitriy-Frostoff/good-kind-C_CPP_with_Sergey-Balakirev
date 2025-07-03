/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191299/step/9?unit=1204287}
 *
 */

#include <stdio.h>
#include <string.h>

#define SURNAME_COUNT 7
#define SURNAME_LENGTH 50
#define PS_SORT_LENGTH (SURNAME_COUNT * SURNAME_LENGTH + 7)

int main(void) {
  // prevent unpredictable characters at arr =>
  // use initialization
  char ps[SURNAME_COUNT][SURNAME_LENGTH] = {0};
  char ps_sort[PS_SORT_LENGTH] = {0};
  int ps_sort_length = 0;
  char *sorted_ascending_arr_of_pointers[SURNAME_COUNT] = {NULL};

  for (int i = 0; i < SURNAME_COUNT; i += 1) {
    // %50s => SURNAME_LENGTH = 50
    if (scanf("%50s", ps[i]) != 1) {
      printf("expected surname with max 50 characters");
      return 0;
    }
  }

  // fill arr of pointers with 'ps' pointers
  for (int i = 0; i < SURNAME_COUNT; i += 1) {
    sorted_ascending_arr_of_pointers[i] = ps[i];
  }

  int arr_size = sizeof(sorted_ascending_arr_of_pointers) /
                 sizeof(*sorted_ascending_arr_of_pointers);

  // sort ascending pointers to the surnames at 'ps' arr
  for (int i = 0; i < arr_size - 1; i += 1) {
    int minElemIndex = i;

    for (int j = i + 1; j < arr_size; j += 1) {
      if ((int)strlen(sorted_ascending_arr_of_pointers[minElemIndex]) >
          (int)strlen(sorted_ascending_arr_of_pointers[j])) {
        minElemIndex = j;
      }
    }

    if (minElemIndex != i) {
      char *temp = sorted_ascending_arr_of_pointers[i];

      sorted_ascending_arr_of_pointers[i] =
          sorted_ascending_arr_of_pointers[minElemIndex];

      sorted_ascending_arr_of_pointers[minElemIndex] = temp;
    }
  }

  // create 'ps_sort' string from sorted pointers to the 'ps' arr of strings
  for (int i = 0; i < SURNAME_COUNT; i += 1) {
    ps_sort_length = (int)strlen(ps_sort);
    strncat(ps_sort, sorted_ascending_arr_of_pointers[i],
            (int)sizeof(ps_sort) - ps_sort_length - 1);
    ps_sort_length = (int)strlen(ps_sort);

    ps_sort[ps_sort_length] = ' ';
  }

  // replace last ' ' with '\0'
  ps_sort[ps_sort_length] = '\0';

  puts(ps_sort);

  /**
   *  макроопределение для тестирования
   *  (не убирать и должно идти непосредственно перед return 0)
   */
  __ASSERT_TESTS__
  return 0;
}
