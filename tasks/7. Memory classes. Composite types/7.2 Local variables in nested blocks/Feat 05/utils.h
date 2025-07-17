#ifndef UTILS_H
#define UTILS_H

#include "./config.h"

char get_natural_num(unsigned int *n);
size_t get_divisors_of_num(unsigned int num, unsigned int arr[],
                           size_t arr_size);
void print_integers(const unsigned int ARR[], size_t ARR_SIZE,
                    size_t nums_count_to_print);

#endif
