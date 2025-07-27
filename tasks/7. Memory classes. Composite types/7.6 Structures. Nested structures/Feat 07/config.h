#ifndef CONFIG_H
#define CONFIG_H

#include <stddef.h>
#include <stdio.h>
#include <string.h>

enum {
  HOURS = 24,
  MINUTES = 60,
  SECONDS = 60,
};

struct tag_time {
  unsigned char hours;
  unsigned char minutes;
  unsigned char seconds;
};

#endif
