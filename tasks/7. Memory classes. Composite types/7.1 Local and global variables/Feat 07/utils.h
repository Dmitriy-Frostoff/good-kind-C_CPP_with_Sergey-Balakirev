#ifndef UTILS_H
#define UTILS_H

#include "./config.h"

size_t get_ints_to_arr(int arr[], size_t arr_size);
int is_num_in_range_1_5(int num);
double mean_ar(const int ar[], size_t len_ar, int (*check_callback)(int));

#endif
