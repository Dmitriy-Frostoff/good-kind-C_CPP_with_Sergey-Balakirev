#ifndef UTILS_H
#define UTILS_H

#include "./config.h"

int get_input_data(WORDS_ARR arr, size_t arr_size, char separator[]);
int is_correct(const char *str);
int get_correct_words(const char (*words)[WORD_LENGTH], int count_words,
                      FUNC_CORRECT filter);

#endif
