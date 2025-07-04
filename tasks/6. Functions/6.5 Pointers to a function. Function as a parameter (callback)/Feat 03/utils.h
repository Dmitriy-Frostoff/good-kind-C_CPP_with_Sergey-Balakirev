#ifndef UTILS_H
#define UTILS_H

#include "./config.h"

int get_string_data(char *str, size_t sizeof_str);
int remove_str_last_n(char *str);
int check_latin_char(char LETTER);
void copy_string(char *dst, size_t max_len_dst, const char *src,
                 int (*spell_callback)(const char LETTER));

#endif
