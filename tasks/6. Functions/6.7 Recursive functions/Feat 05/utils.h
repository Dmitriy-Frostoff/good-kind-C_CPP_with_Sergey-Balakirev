#ifndef UTILS_H
#define UTILS_H

#include "./config.h"

size_t to_flat(short *v, size_t MAX_LEN_V, short *table[], size_t len,
               size_t count_v, size_t indx_t, size_t indx);

void print_array_values(const short arr[], size_t ARR_SIZE,
                        size_t qunatity_to_print);

#endif
