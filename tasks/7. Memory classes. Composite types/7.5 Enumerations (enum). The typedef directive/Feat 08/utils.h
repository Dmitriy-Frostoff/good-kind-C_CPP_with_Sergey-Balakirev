#ifndef UTILS_H
#define UTILS_H

#include "./config.h"

size_t get_input_data(NOTES arr[], size_t arr_size);
char get_major(NOTES note);
size_t check_notes(const NOTES notes_arr[], size_t notes_arr_size,
                   NOTES major_notes_arr[], size_t major_notes_arr_size,
                   check_major_callback callback);
void print_major_notes(const NOTES arr[], size_t arr_size, size_t quantity);

#endif
