#ifndef UTILS_H
#define UTILS_H

#include "./config.h"

int get_int_nums(short arr[], size_t size_of_arr, size_t max_num_count);
void *expand_array(short *ptr, size_t *len, short fill);
void print_integers(const short ARR[], size_t SIZE_OF_ARR,
                    size_t nums_count_to_print);
#endif
