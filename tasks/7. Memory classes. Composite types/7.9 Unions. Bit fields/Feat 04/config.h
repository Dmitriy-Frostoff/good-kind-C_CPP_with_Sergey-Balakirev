#ifndef CONFIG_H
#define CONFIG_H

#include <stdio.h>

typedef enum global_variables { coord_int = 1, coord_double = 2 } TYPE_COORD;

typedef union union_coordinates_data {
  int coord_i;
  double coord_d;
} COORD;

typedef struct struct_point {
  TYPE_COORD type;
  COORD x;
  COORD y;
} POINT2;

#endif
