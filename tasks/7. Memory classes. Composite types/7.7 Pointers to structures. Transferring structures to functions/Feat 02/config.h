#ifndef CONFIG_H
#define CONFIG_H

#include <stdio.h>

/**
 *  @details
 *  char type - type of geometric figure
 *  int x0, y0 - coordinates of upper left corner
 *  int x1, y1 - coordinates of bottom right corner
 *
 */
typedef struct tag_geom {
  char type;
  int x0;
  int y0;
  int x1;
  int y1;
} FIGURE;

#endif
