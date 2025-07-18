#ifndef UTILS_H
#define UTILS_H

#include "./config.h"

char get_natural_num(unsigned int *n);
void get_eratosthen_sieve(unsigned short arr[], size_t arr_size);
size_t get_prime_factors_of_num(unsigned int num, unsigned int arr[],
                                size_t arr_size,
                                void (*callback)(unsigned short arr[],
                                                 size_t arr_size));
void print_integers(const unsigned int ARR[], size_t ARR_SIZE,
                    size_t nums_count_to_print);

#endif
