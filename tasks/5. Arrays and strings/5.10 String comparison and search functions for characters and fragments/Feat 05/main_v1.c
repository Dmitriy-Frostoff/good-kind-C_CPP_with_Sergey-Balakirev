/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191300/step/7?unit=1204288}
 *
 */

/*
 * Громоздко... Надо попробовать через цикл for + поиск символа + копирование в
 * новую строку (предотвращение мутации входных данных и заодно вывода нужных
 * данных). `strtok` мутирует исходные данные(((
 */

#include <stdio.h>
#include <string.h>

#define STR_SIZE 100

int main(void) {
  char str[STR_SIZE] = {0};
  char str_copy[STR_SIZE] = {0};
  char res_str[STR_SIZE] = {0};
  int res_str_size = (int)sizeof(res_str);
  int str_len = 0;

  char *ptr_str = NULL;
  char *arr_of_str_ptrs[STR_SIZE] = {NULL};
  const char WORD_DELIMETER[] = "-";
  const int WORD_DELIMETER_LENGTH = (int)strlen(WORD_DELIMETER);
  int actual_len_arr_of_str_ptrs = 0;

  fgets(str, sizeof(str) - 1, stdin);

  char *ptr_n = strrchr(str, '\n');

  if (ptr_n != NULL) {
    *ptr_n = '\0';
  }

  str_len = (int)strlen(str);

  // empty data ? return
  if (!str_len) {
    puts("empty input data");
    return 0;
  }

  // prevent 'str' arr mutation
  strncpy(str_copy, str, (int)strlen(str));
  // caution!!! 'strtok' mutates original string!
  // It replaces every first occurance of WORD_DELIMETER with '\0'
  // cpp--znacheniya => {cpp\0-znacheniya}
  ptr_str = strtok(str_copy, WORD_DELIMETER);

  // fill array of pointers to the string with '-' delimeter
  int index_at_arr_of_str_ptrs = 0;

  while (ptr_str != NULL) {
    arr_of_str_ptrs[index_at_arr_of_str_ptrs] = ptr_str;
    ptr_str = strtok(NULL, WORD_DELIMETER);
    index_at_arr_of_str_ptrs += 1;
  }

  // get actual quantity of elems
  while (arr_of_str_ptrs[actual_len_arr_of_str_ptrs] != NULL) {
    actual_len_arr_of_str_ptrs += 1;
  }

  // create res_str from the pointers data
  for (int i = 0; i < actual_len_arr_of_str_ptrs; i += 1) {
    if (str_copy[0] == '-') {
      res_str[0] = '-';
    }

    // add next string part ("cpp-" => "cpp-znacheniya")
    strncat(res_str, arr_of_str_ptrs[i], res_str_size - 1 - strlen(res_str));

    // add WORD_DELIMETER (e.g. "-") e.g. "cpp" => "cpp-"
    // WORD_DELIMETER_LENGTH => to just copy necessary chars and to prevent
    // copiing noise data of memory
    if (res_str_size - 1 - strlen(res_str) > 1) {
      strncat(res_str, WORD_DELIMETER, WORD_DELIMETER_LENGTH);
    }
  }

  // replace last '-' , if 'str' doesn't end with it
  if (str[(int)strlen(str) - 1] != '-') {
    res_str[(int)strlen(res_str) - 1] = '\0';
  }

  // add '\0' at the end, if 'res_str' doesn't end with '\0'
  if (res_str[(int)strlen(res_str)] != '\0') {
    res_str[(int)strlen(res_str)] = '\0';
  }

  puts(res_str);

  return 0;
}
