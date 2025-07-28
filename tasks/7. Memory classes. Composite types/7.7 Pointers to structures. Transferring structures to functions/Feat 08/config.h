#ifndef CONFIG_H
#define CONFIG_H

#include <stddef.h>
#include <stdio.h>

enum {
  ARR_SIZE = 20,
};

/**
 *  @details
 *  {int} x - coordinate x of a point
 *  {int} y - coordinate y of a point
 *
 */
typedef struct point_coordinates {
  int x;
  int y;
} POINT;

/**
 *  @details
 *  {double} mean_x - mean of all x coordinates
 *  {double} mean_y - mean of all y coordinates
 *
 */
typedef struct mean_data {
  double mean_x;
  double mean_y;
} DATA;

#endif
