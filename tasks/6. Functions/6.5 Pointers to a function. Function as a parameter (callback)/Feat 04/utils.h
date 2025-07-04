#ifndef UTILS_H
#define UTILS_H

#include "./config.h"

int get_numbers_to_arr(int arr[], size_t arr_size);
int is_even(int num);
int sum_ar(const int arr[], size_t len_arr, int (*check_callback)(const int));

#endif
