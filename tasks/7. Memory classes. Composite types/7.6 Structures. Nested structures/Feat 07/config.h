#ifndef CONFIG_H
#define CONFIG_H

#include <stdio.h>

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
