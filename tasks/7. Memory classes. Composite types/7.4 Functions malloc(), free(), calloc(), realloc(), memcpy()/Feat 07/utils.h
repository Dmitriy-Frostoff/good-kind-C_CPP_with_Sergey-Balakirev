#ifndef UTILS_H
#define UTILS_H

#include "./config.h"

size_t get_int_nums(int arr[], size_t size_of_arr, size_t max_num_count);
void *allocate_clear_memory(size_t nums_quantity, size_t sizeof_elem);
void print_integers(const int ARR[], size_t SIZE_OF_ARR,
                    size_t nums_count_to_print);
#endif
