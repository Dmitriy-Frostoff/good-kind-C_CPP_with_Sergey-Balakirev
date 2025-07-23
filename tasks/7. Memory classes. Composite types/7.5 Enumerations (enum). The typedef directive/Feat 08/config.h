#ifndef CONFIG_H
#define CONFIG_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef enum {
  _do = 1,
  _re = 2,
  _mi = 3,
  _fa = 4,
  _sol = 5,
  _la = 6,
  _si = 7
} NOTES;

typedef char (*check_major_callback)(NOTES note);

#endif
