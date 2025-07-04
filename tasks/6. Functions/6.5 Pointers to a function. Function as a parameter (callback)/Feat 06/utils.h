#ifndef UTILS_H
#define UTILS_H

#include "./config.h"

int get_string_data(char *str, size_t sizeof_str);
int remove_str_last_n(char *str);
int match_ab(char A, char B);
void sort_string(char *str, size_t max_len,
                 int (*compare_callback)(const char, const char));

#endif
