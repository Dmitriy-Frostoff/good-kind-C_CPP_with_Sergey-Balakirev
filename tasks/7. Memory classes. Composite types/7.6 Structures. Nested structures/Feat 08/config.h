#ifndef CONFIG_H
#define CONFIG_H

#include <stddef.h>
#include <stdio.h>

enum {
  total_points = 100,
};

struct tag_point_3d {
  int x;
  int y;
  int z;
};

#endif
