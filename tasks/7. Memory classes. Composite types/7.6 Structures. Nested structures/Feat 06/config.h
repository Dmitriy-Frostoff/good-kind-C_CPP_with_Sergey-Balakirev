#ifndef CONFIG_H
#define CONFIG_H

#include <stddef.h>
#include <stdio.h>
#include <string.h>

enum {
  WORD_LENGTH = 50,
};

struct tag_fio {
  char firstname[WORD_LENGTH];
  char otch[WORD_LENGTH];
  char lastname[WORD_LENGTH];
};

struct tag_student {
  struct tag_fio fio;
  short old;
  short height;
  short weight;
};

#endif
