#ifndef UTILS_H
#define UTILS_H

#include "./config.h"

OBJ *push(OBJ *top, const char *url);
OBJ *pop(OBJ *top);
OBJ *empty_stack(OBJ *top, empty_stack_callback callback);

#endif
