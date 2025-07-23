#ifndef UTILS_H
#define UTILS_H

#include "./config.h"

int get_input_data(enum calc_types *type, double *width, double *height);
double calc_rect(double width, double height, enum calc_types type);

#endif
