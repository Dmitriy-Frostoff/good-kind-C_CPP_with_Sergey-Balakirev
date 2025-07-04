#ifndef UTILS_H
#define UTILS_H

#include "./config.h"

size_t range_to_ar(int *ptr_a, size_t MAX_LEN, int from, int TO, size_t count);

int get_max_range_value();
void print_arr_nums(const int arr[], size_t SIZEOF_ARR,
                    size_t quantity_to_print);

#endif
