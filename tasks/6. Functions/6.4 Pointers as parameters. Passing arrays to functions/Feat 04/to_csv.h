#ifndef TO_CSV_H
#define TO_CSV_H

#include "./config.h"

int str_count_free_chars(const char *str, int size_of_str);
int to_csv(char *str, const double arr[], int arr_length);

#endif
