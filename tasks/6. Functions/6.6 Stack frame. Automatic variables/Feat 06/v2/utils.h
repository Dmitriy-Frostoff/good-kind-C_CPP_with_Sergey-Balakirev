#ifndef UTILS_H
#define UTILS_H

#include "./config.h"

int get_string_data(char *str, size_t sizeof_str);
int remove_str_last_n(char *str);
void strip_str(char *str, char *str_template);

#endif
