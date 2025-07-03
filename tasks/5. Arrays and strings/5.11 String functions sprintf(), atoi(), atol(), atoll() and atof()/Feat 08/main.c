/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191301/step/10?unit=1204289}
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TOTAL 10
#define MAX_STR_LENGTH 50

int main(void) {
  char str[TOTAL][MAX_STR_LENGTH];
  char *p_sort[TOTAL] = {NULL};
  int sizeof_p_sort = sizeof(p_sort) / sizeof(*p_sort);
  const char STR_DELIMETER_SEMICOLON[] = ";";
  const char STR_DELIMETER_COLON[] = ":";
  const char STR_DELIMETER_SPACE[] = " ";
  // size with a large headroom for " " delimters
  char res_str[TOTAL * MAX_STR_LENGTH] = {0};
  int sizeof_res_str = sizeof(res_str);

  int count = 0;

  // set the data to 'str'
  // input template: "<good name>: int<id>; id<price>; double<weight>"
  while (count < TOTAL && fgets(str[count], sizeof(str) - 1, stdin)) {
    // remove last '\n' from the 'str'
    char *ptr_n = strrchr(str[count], '\n');

    if (ptr_n != NULL) {
      *ptr_n = '\0';
    }

    count += 1;
  }

  // fill the 'p_sort' arr with pointers to the strings
  for (int i = 0; i < sizeof_p_sort; i += 1) {
    p_sort[i] = str[i];
  }

  // sort descending 'p_sort' over the good weight
  for (int i = 0; i < sizeof_p_sort; i += 1) {
    // empty string ? => continue
    if (*str[i] == '\0') {
      continue;
    }

    int current_index = i;

    // *STR_DELIMETER_SEMICOLON same as STR_DELIMETER_SEMICOLON[0] =>
    //  pointer to the first char in the current 'str'
    char *ptr_current_weight =
        strrchr(p_sort[current_index], *STR_DELIMETER_SEMICOLON);

    if (ptr_current_weight == NULL) {
      puts("incorrect weight value. Expected double<weight> after last ';'");
      return 0;
    }

    // ""...; double<weight>" => "...double<weight>" => "double<weight>"
    double current_weight = atof(ptr_current_weight + 1);

    if (current_weight == 0) {
      puts("incorrect weight value. Expected double<weight> after last ';'");
      return 0;
    }

    // compare and switch the current_index through over the strings
    // in the 'p_sort' from the sceond to the last one
    for (int j = i + 1; j < sizeof_p_sort; j += 1) {
      // empty string ? => continue
      if (*str[j] == '\0') {
        continue;
      }

      char *ptr_compare_weight = strrchr(p_sort[j], *STR_DELIMETER_SEMICOLON);

      if (ptr_compare_weight == NULL) {
        puts("incorrect weight value. Expected double<weight> after last ';'");
        return 0;
      }

      // ""...; double<weight>" => "...double<weight>" => "double<weight>"
      double compare_weight = atof(ptr_compare_weight + 1);

      if (compare_weight == 0) {
        puts("incorrect weight value. Expected double<weight> after last ';'");
        return 0;
      }

      // compare 'current_weight'(current_index) with
      //  'compare_weight'('j' => indexes after 'i')
      if (current_weight < compare_weight) {
        current_index = j;
        current_weight = compare_weight;
      }
    }

    // current_index had been changed ? => switch the pointers
    if (current_index != i) {
      char *temp = p_sort[i];
      p_sort[i] = p_sort[current_index];
      p_sort[current_index] = temp;
    }
  }

  // fill 'res_str' with sorted 'good names'
  for (int i = 0; i < sizeof_p_sort; i += 1) {
    // empty string ? => continue
    if (*p_sort[i] == '\0') {
      continue;
    }

    char current_good_name[MAX_STR_LENGTH] = {0};
    char *ptr_to_colon_delimeter = strchr(p_sort[i], *STR_DELIMETER_COLON);

    if (ptr_to_colon_delimeter == NULL) {
      puts("incorrect weight value. Expected double<weight> after last ';'");
      return 0;
    }

    // check that sizeof(current_good_name) is enough to contain
    //  the <good name> length + '\0'
    if (sizeof(current_good_name) - (p_sort[i] - ptr_to_colon_delimeter + 1) >
        0) {
      // ptr_to_colon_delimeter last char of <goodname>
      // p_sort[i] => begining of <goodname>
      // ptr_to_colon_delimeter > p_sort[i] (!!!)
      strncpy(current_good_name, p_sort[i], ptr_to_colon_delimeter - p_sort[i]);
    }

    // copy 'current_good_name' to the 'res_str'
    if (sizeof_res_str - ((int)strlen(res_str) + 1) > 0) {
      strcat(res_str, current_good_name);
    }

    // add " " after <goodname> at the 'res_str' if <goodname> is not last in
    // the 'p_sort'
    if (i != sizeof_p_sort - 1) {
      if (sizeof_res_str - ((int)strlen(res_str) + 1) > 0) {
        strcat(res_str, STR_DELIMETER_SPACE);
      }
    }
  }

  puts(res_str);

  return 0;
}
