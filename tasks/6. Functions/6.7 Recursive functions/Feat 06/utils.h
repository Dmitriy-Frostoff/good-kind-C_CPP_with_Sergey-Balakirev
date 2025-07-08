#ifndef UTIL_H
#define UTIL_H

#include "./config.h"

void get_string_data(char *str, size_t str_len);
void remove_last_n(char *str);
void str_to_low(char *str);
void translate_str(const char *str, size_t str_len, char *translated_str,
                   size_t translated_str_len, const char *LATIN_LETTERS,
                   size_t LATIN_LETTERS_TEMPLATE_LENGTH,
                   const char *MORZE_SYMBOLS[]);

#endif
