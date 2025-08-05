#ifndef CONFIG_H
#define CONFIG_H

#include <stddef.h>
#include <stdio.h>

enum global_variables { SIZE_OF_ARR = 5 };

typedef enum types_variables { param_int = 1, param_double = 2 } TYPE_PARAM;

typedef union union_data {
  int data_i;
  double data_d;
} DATA;

#endif
