#ifndef UTILS_H
#define UTILS_H

#include "./config.h"

int get_criteria_for_sum(void);
int get_numbers_to_arr(int arr[], size_t arr_size);
int count_sum_via_chosen_func(
    int ITEM,
    int (*sum_ar_callback)(const int arr[], size_t len_arr,
                           int (*check_callback)(const int)),
    const int arr[], size_t len_arr, int (*funcs[])(int), size_t sizeof_funcs);
int is_odd(int num);
int is_positive(int num);
int is_negative(int num);
int deflt(int num);
int sum_ar(const int arr[], size_t len_arr, int (*check_callback)(const int));

#endif
