#ifndef UTILS_H
#define UTILS_H

#include "./config.h"

void get_string_data(char *str, size_t str_len);
void remove_last_n(char *str);
int get_data_csv(double arr[], size_t SIZE_OF_ARR, char *str);
void print_arr_nums(const double arr[], size_t NUMS_QUANTITY);

#endif
