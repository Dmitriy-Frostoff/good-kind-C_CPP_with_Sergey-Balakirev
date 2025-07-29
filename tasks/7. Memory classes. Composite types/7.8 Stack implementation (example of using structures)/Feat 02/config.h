#ifndef CONFIG_H
#define CONFIG_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum global_variables {
  URL_SIZE = 1024,
  ID_SIZE = 16,
};

typedef struct tag_obj {
  char id[ID_SIZE];
  char url[URL_SIZE];
  struct tag_obj *next;
} OBJ;

typedef OBJ *(*empty_stack_callback)(OBJ *top);

#endif
